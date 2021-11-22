#include <fstream>
#include <vector>

using namespace std;

int leftBinSearch(vector<int> &values, int searchValue)
{
    int left = -1, right = values.size(), mid = (left + right) / 2;

    while (left < right - 1)
    {
        mid = (left + right) / 2;

        (values[mid] < searchValue) ? left = mid : right = mid;
    }

    return right;
}

int rightBinSearch(vector<int> &values, int searchValue)
{
    int left = -1, right = values.size(), mid = (left + right) / 2;

    while (left < right - 1)
    {
        mid = (left + right) / 2;

        (values[mid] <= searchValue) ? left = mid : right = mid;
    }

    return right;
}

int main()
{
    ifstream in("binsearch.in");
    ofstream out("binsearch.out");

    int n;
    in >> n;

    vector<int> values(n + 1);



    for (int i = 0; i < n; i++)
    {
        in >> values[i];
    }

    int m;
    in >> m;

    for (int i = 0; i < m; i++)
    {
        int searchValue;
        in >> searchValue;

        int leftIn = leftBinSearch(values, searchValue);
        int rightIn = rightBinSearch(values, searchValue);

        if (leftIn + 1 > rightIn)
        {
            out << -1 << " " << -1 << "\n";
        }
        else
        {
            out << leftIn + 1 << " " << (rightIn == n + 1 ? rightIn - 1 : rightIn) << "\n";
        }
    }

    in.close();
    out.close();
    return 0;
}