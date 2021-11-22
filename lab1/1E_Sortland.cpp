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
    ifstream in("sortland.in");
    ofstream out("sortland.out");

    int n;
    in >> n;

    vector<pair<double, int>> sortingStorage(n);

    for (int i = 0; i < n; i++)
    {
        double competency;
        in >> competency;

        sortingStorage[i] = {competency, i + 1};
    }

    for (int i = 0; i < sortingStorage.size(); i++)
    {
        int j = i;
        pair<double, int> temp = sortingStorage[i];

        while (j > 0 && temp.first < sortingStorage[j - 1].first)
        {
            sortingStorage[j] = sortingStorage[j - 1];
            j--;
        }

        sortingStorage[j] = temp;
    }

    out << sortingStorage[0].second << " " << sortingStorage[(n - 1) / 2].second << " " << sortingStorage[n - 1].second;

    in.close();
    out.close();
    return 0;
}
