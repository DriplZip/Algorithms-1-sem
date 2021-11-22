#include <cstdlib>
#include <fstream>

using namespace std;

typedef struct stack
{
    int value;
    struct stack *next;
} stack_t;

stack *top = nullptr;

void push(int value)
{
    stack_t *node = (stack_t *) (malloc(sizeof(stack_t)));
    node->value = value;
    node->next = top;

    top = node;
}

int pop()
{
    stack_t *node = top->next;
    int value = top->value;

    free(top);

    top = node;

    return value;
}

bool empty()
{
    if (top == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void clear()
{
    while (top != nullptr)
    {
        stack_t *temp = top->next;

        free(top);

        top = temp;
    }
}

int main()
{
    ifstream in("postfix.in");
    ofstream out("postfix.out");

    stack_t stack;
    stack.next = nullptr;

    char symbol;

    while (in >> symbol)
    {
        if (symbol == ' ') continue;

        int a = 0, b = 0;

        if (symbol == '+')
        {
            b = pop();
            a = pop();

            push(a + b);

            continue;
        }

        if (symbol == '-')
        {
            b = pop();
            a = pop();

            push(a - b);

            continue;
        }

        if (symbol == '*')
        {
            b = pop();
            a = pop();

            push(a * b);

            continue;
        }

        int p = symbol - '0';

        push(p);
    }

    out << pop();

    clear();

    in.close();
    out.close();
    return 0;
}
