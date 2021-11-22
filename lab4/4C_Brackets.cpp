#include <cstdlib>
#include <fstream>

using namespace std;

typedef struct stack
{
    char value;
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

char pop()
{
    stack_t *node = top->next;
    char value = top->value;

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

int main()
{
    ifstream in("brackets.in");
    ofstream out("brackets.out");

    stack_t stack;
    stack.next = nullptr;

    string brackets;

    bool flag = true;

    while (in >> brackets)
    {
        for (int i = 0; i < brackets.size(); i++)
        {
            if (brackets[i] == ')' || brackets[i] == ']')
            {
                if (empty())
                {
                    out << "NO\n";

                    flag = false;
                    break;
                }

                char temp = pop();

                if (temp == '(' && brackets[i] != ')' || temp == '[' && brackets[i] != ']')
                {
                    out << "NO\n";

                    flag = false;
                    break;
                }
            } else
            {
                push(brackets[i]);
            }
        }

        if (flag && empty())
        {
            out << "YES\n";
        }
        else if (flag)
        {
            out << "NO\n";
        }

        flag = true;

        while (top != nullptr)
        {
            stack_t *temp = top->next;

            free(top);

            top = temp;
        }


    }

    in.close();
    out.close();
    return 0;
}
