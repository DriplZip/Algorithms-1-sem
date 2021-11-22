#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>


using namespace std;

void merge(vector<pair<string, string>> &sortedVec, int left, int mid, int right)
{
    vector<pair<string, string>> temp(right - left + 1);

    int leftToMid = 0, midToRight = 0;

    while (left + leftToMid < mid && mid + midToRight < right)
    {
        if (sortedVec[left + leftToMid].first <= sortedVec[mid + midToRight].first)
        {
            temp[leftToMid + midToRight] = sortedVec[left + leftToMid];

            leftToMid++;
        }
        else
        {
            temp[leftToMid + midToRight] = sortedVec[mid + midToRight];

            midToRight++;
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

void splittingVec(vector<pair<string, string>> &sortedVec, int left, int right)
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
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    ifstream in("race.in");
    ofstream out("race.out");

    int n;
    in >> n;

    vector<pair<string, string>> sortedVec(n);

    for (int i = 0; i < n; i++)
    {
        string region, name;

        getline(in, region, ' ');
        in >> name;

        region[0] = ' ';
        sortedVec[i] = {region, name};
    }

    splittingVec(sortedVec, 0, n);


    out << "===" << sortedVec[0].first << " ===" << endl << sortedVec[0].second << endl;

    for (int i = 1; i < n; i++)
    {
        if (sortedVec[i].first != sortedVec[i - 1].first)
        {
            out << "===" << sortedVec[i].first << " ===" << endl;
        }

        out << sortedVec[i].second << endl;
    }

    in.close();
    out.close();
    return 0;
}
