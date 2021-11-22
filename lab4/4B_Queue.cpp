#include <cstdlib>
#include <fstream>

using namespace std;

typedef struct queue
{
    int value;
    queue *next;
} queue_t;

queue_t *head = nullptr;
queue_t *tail = nullptr;

void push(int pushElement)
{
    queue_t *node = (queue_t *) malloc(sizeof(queue_t));

    node->value = pushElement;
    node->next = nullptr;

    if (head == nullptr && tail == nullptr)
    {
        tail = node;
        head = node;
    } else
    {
        tail->next = node;

        tail = node;
    }
}

int pop()
{
    int value = head->value;

    queue_t *temp = head;

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
    }

    free(temp);

    return value;
}

int main()
{
    ifstream in("queue.in");
    ofstream out("queue.out");

    int n;
    in >> n;

    queue_t queue;
    queue.next = nullptr;

    for (int i = 0; i < n; i++)
    {
        char sign;
        int inValue;

        in >> sign;

        if (sign == '+')
        {
            in >> inValue;
            push(inValue);
        } else
        {
            out << pop() << '\n';
        }
    }

    in.close();
    out.close();
    return 0;
}