#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>


using namespace std;

int splitting(vector<int> &sortedVec, int left, int right)
{
    int separator = sortedVec[left];
    int i = left, j = right;

    while (i <= j)
    {
        while (sortedVec[i] < separator)
        {
            i++;
        }

        while (sortedVec[j] > separator)
        {
            j--;
        }

        if (i >= j) break;

        swap(sortedVec[i++], sortedVec[j--]);
    }

    return j;
}

void qsort(vector<int> &sortedVec, int left, int right)
{
    if (left < right)
    {
        int bord = splitting(sortedVec, left, right);

        qsort(sortedVec, left, bord);
        qsort(sortedVec, bord + 1, right);
    }
}

int main()
{
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    ifstream in("sort.in");
    ofstream out("sort.out");

    int n;
    in >> n;

    vector<int> sortedVec(n);

    for (int i = 0; i < n; i++)
    {
        in >> sortedVec[i];
    }

    qsort(sortedVec, 0, n - 1);

    for (int a : sortedVec)
    {
        out << a << " ";
    }

    in.close();
    out.close();
    return 0;
}
