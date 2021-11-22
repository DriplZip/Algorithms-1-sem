#define _USE_MATH_DEFINES
#define ll long long
#define _CRT_SECURE_NO_WARNINGS
#define maxLl 2e18 + 1
#define maxI 2e9 + 1

#include <fstream>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <string>
#include <set>
#include <deque>
#include <cctype>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <regex> // regex_match(question, regex(".*str.*"))) // ���� � ������ question ����� str
#include <ctime>

using namespace std;

int main()
{
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    ifstream in("smallsort.in");
    ofstream out("smallsort.out");

    int n;
    in >> n;

    vector<int> sortingVector(n);

    for (int i = 0; i < n; i++)
        in >> sortingVector[i];

    for (int i = 0; i < sortingVector.size(); i++)
    {
        int temp = sortingVector[i], j = i;

        while (j > 0 && temp < sortingVector[j - 1])
        {
            sortingVector[j] = sortingVector[j - 1];
            j--;
        }

        sortingVector[j] = temp;
    }

    for (int i = 0; i < n; i++)
        out << sortingVector[i] << " ";

    in.close();
    out.close();
    return 0;
}
