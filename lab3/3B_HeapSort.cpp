#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void maxHeapify(vector<int> &vec, int index, int size)
{
    int maxIndex = index;

    int leftBranch = 2 * index + 1;
    int rightBranch = 2 * index + 2;

    if (leftBranch < size && vec[leftBranch] > vec[maxIndex]) maxIndex = leftBranch;

    if (rightBranch < size && vec[rightBranch] > vec[maxIndex]) maxIndex = rightBranch;

    if (maxIndex != index)
    {
        swap(vec[index], vec[maxIndex]);

        maxHeapify(vec, maxIndex, size);
    }
}

void heapSort(vector<int> &vec, int size)
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

int main()
{
    ifstream in("sort.in");
    ofstream out("sort.out");

    int n;
    in >> n;

    vector<int> sortedVec(n);

    for (int i = 0; i < n; i++)
    {
        in >> sortedVec[i];
    }

    heapSort(sortedVec, n);

    for (int i = 0; i < n; i++)
    {
        out << sortedVec[i] << " ";
    }

    in.close();
    out.close();
    return 0;
}
