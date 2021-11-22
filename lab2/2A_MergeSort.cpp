#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


using namespace std;

void merge(vector<int> &sortedVec, int left, int mid, int right)
{
    int leftToMid = 0;
    int midToRight = 0;

    vector<int> mergeVector(right - left + 1);

    while (left + leftToMid < mid && mid + midToRight < right)
    {
        if (sortedVec[left + leftToMid] < sortedVec[mid + midToRight])
        {
            mergeVector[leftToMid + midToRight] = sortedVec[left + leftToMid];
            leftToMid++;
        }
        else
        {
            mergeVector[leftToMid + midToRight] = sortedVec[mid + midToRight];
            midToRight++;
        }
    }

    while (left + leftToMid < mid)
    {
        mergeVector[leftToMid + midToRight] = sortedVec[left + leftToMid];
        leftToMid++;
    }

    while (mid + midToRight < right)
    {
        mergeVector[leftToMid + midToRight] = sortedVec[mid + midToRight];
        midToRight++;
    }

    for (int i = 0; i < leftToMid + midToRight; ++i)
    {
        sortedVec[left + i] = mergeVector[i];
    }
}

void splittingVec(vector<int> &sortedVec, int left, int right)
{
    if (left + 1 >= right)
    {
        return;
    }

    int mid = (left + right) / 2;

    splittingVec(sortedVec, left, mid);
    splittingVec(sortedVec, mid, right);

    merge(sortedVec, left, mid, right);
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

    splittingVec(sortedVec, 0, n);

    for (int itemVec: sortedVec)
    {
        out << itemVec << " ";
    }

    in.close();
    out.close();
    return 0;
}