#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>


using namespace std;



int main()
{
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    ifstream in("antiqs.in");
    ofstream out("antiqs.out");

    int n;
    in >> n;

    vector<int> sortedVec(n);

    for (int i = 1; i <= n; i++)
    {
        sortedVec[i - 1] = i;
    }

    for (int i = 0; i < n; i++)
    {
        swap(sortedVec[i], sortedVec[i / 2]);
    }

    for (int a : sortedVec)
    {
        out << a << " ";
    }

    in.close();
    out.close();
    return 0;
}
