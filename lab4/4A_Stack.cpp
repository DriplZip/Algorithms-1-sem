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

    delete top;

    top = node;

    return value;
}

int main()
{
    ifstream in("stack.in");
    ofstream out("stack.out");

    int n;
    in >> n;

    stack_t stack;
    stack.next = nullptr;

    for (int i = 0; i < n; i++)
    {
        char sign;
        in >> sign;

        if (sign == '+')
        {
            int value;
            in >> value;

            push(value);
        } else
        {
            out << pop() << endl;
        }
    }

    in.close();
    out.close();
    return 0;
}
