#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>


using namespace std;

void merge(vector<int> &sortedVec, int left, int mid, int right, long long &count)
{
    vector<int> temp(right - left + 1);

    int leftToMid = 0, midToRight = 0, countInv = 0;

    while (left + leftToMid < mid && mid + midToRight < right)
    {
        if (sortedVec[left + leftToMid] <= sortedVec[mid + midToRight])
        {
            temp[leftToMid + midToRight] = sortedVec[left + leftToMid];

            leftToMid++;
        }
        else
        {
            temp[leftToMid + midToRight] = sortedVec[mid + midToRight];

            midToRight++;
            count += (mid - left) - leftToMid;
        }
    }

    while (left + leftToMid < mid)
    {
        temp[leftToMid + midToRight] = sortedVec[left + leftToMid];

        leftToMid++;
    }

    while (mid + midToRight < right)
    {
        temp[leftToMid + midToRight] = sortedVec[mid + midToRight];

        midToRight++;
    }

    for (int i = 0; i < leftToMid + midToRight; i++)
    {
        sortedVec[left + i] = temp[i];
    }
}

void splittingVec(vector<int> &sortedVec, int left, int right, long long &count)
{
    if (left + 1 >= right)
    {
        return;
    }

    int mid = (left + right) / 2;

    splittingVec(sortedVec, left, mid, count);
    splittingVec(sortedVec, mid, right, count);

    merge(sortedVec, left, mid, right, count);
}

int main()
{
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    ifstream in("inversions.in");
    ofstream out("inversions.out");

    long long n, count = 0;
    in >> n;

    vector<int> sortedVec(n);

    for (int i = 0; i < n; i++)
    {
        in >> sortedVec[i];
    }

    splittingVec(sortedVec, 0, n, count);

    out << count;

    in.close();
    out.close();
    return 0;
}
