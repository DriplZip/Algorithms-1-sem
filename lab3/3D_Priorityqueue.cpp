#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct cell
{
    int value;
    int index;
};

void maxHeapify(vector<cell> &vec, int index, int size)
{
    int maxIndex = index;

    int leftBranch = 2 * index + 1;
    int rightBranch = 2 * index + 2;

    if (leftBranch < size && vec[leftBranch].value > vec[maxIndex].value) maxIndex = leftBranch;

    if (rightBranch < size && vec[rightBranch].value > vec[maxIndex].value) maxIndex = rightBranch;

    if (maxIndex != index)
    {
        swap(vec[index], vec[maxIndex]);

        maxHeapify(vec, maxIndex, size);
    }
}

void heapSort(vector<cell> &vec, int size)
{
    for (int i = size / 2; i >= 0; i--)
    {
        maxHeapify(vec, i, size);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        swap(vec[0], vec[i]);

        maxHeapify(vec, 0, i);
    }
}

void push(vector<cell> &vec, int x, int index)
{
    vec.push_back({x, index});

    if (!vec.empty())
    {
        for (int i = vec.size() / 2 - 1; i >= 0; i--)
        {
            maxHeapify(vec, i, vec.size());
        }
    }

}

int extractMin(vector<cell> &vec)
{
    int minValue = 2000000000, minValueIndex = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].value < minValue)
        {
            minValue = vec[i].value;
            minValueIndex = i;
        }
    }

    swap(vec[minValueIndex], vec[vec.size() - 1]);

    vec.pop_back();

    for (int i = vec.size() / 2 - 1; i >= 0; i--)
    {
        maxHeapify(vec, i, vec.size());
    }

    return minValue;
}

void decreaseKey(vector<cell> &vec, int x, int y)
{
    int xIndex = -1;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].index == x)
        {
            xIndex = i;

            break;
        }

    }

    vec[xIndex].value = y;
}

int main()
{
    ifstream in("priorityqueue.in");
    ofstream out("priorityqueue.out");

    vector<cell> prQueue;

    string str;

    int strIndex = 1;

    while(in >> str)
    {
        if (str == "push")
        {
            int value;
            in >> value;

            push(prQueue, value, strIndex);
        }

        if (str == "extract-min")
        {
            if (prQueue.empty())
            {
                out << "*\n";
            }
            else
            {
                out << extractMin(prQueue) << "\n";
            }
        }

        if (str == "decrease-key")
        {
            int x, y;
            in >> x >> y;

            decreaseKey(prQueue, x, y);
        }

        strIndex++;
    }

    in.close();
    out.close();
    return 0;
}