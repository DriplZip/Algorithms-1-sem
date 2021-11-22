#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void countingSort(vector<string> &vec, int index)
{
    vector<string> outVec(vec.size());

    vector<int> temp(26, 0);

    for (int i = 0; i < vec.size(); i++)
    {
        temp[vec[i][index] - 'a']++;
    }

    for (int i = 1; i < temp.size(); i++)
    {
        temp[i]+= temp[i - 1];
    }

    for (int i= vec.size() - 1; i >= 0; i--)
    {
        outVec[temp[vec[i][index] - 'a'] - 1] = vec[i];
        temp[vec[i][index] - 'a']--;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = outVec[i];
    }
}

void radixSort(vector<string> &vec, int sizeOfString, int iteration)
{
    for (int i = sizeOfString - 1; i > (sizeOfString - iteration - 1); i--)
    {
        countingSort(vec, i);
    }
}

int main()
{
    ifstream in("radixsort.in");
    ofstream out("radixsort.out");

    int n, sizeOfString, k;
    in >> n >> sizeOfString >> k;

    vector<string> sortedVec(n);

    for (int i = 0; i < n; i++)
    {
        in >> sortedVec[i];
    }

    radixSort(sortedVec, sizeOfString, k);

    for (int i = 0; i < n; i++)
    {
        out << sortedVec[i] << endl;
    }

    in.close();
    out.close();
    return 0;
}