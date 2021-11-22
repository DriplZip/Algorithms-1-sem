#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("isheap.in");
    ofstream out("isheap.out");

    int n;
    in >> n;

    vector<int> isHeap(n + 1);

    for (int i = 1; i <= n; i++)
    {
        in >> isHeap[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (2 * i >= n) continue;

        if (isHeap[i] > isHeap[2 * i] || isHeap[i] > isHeap[2 * i + 1])
        {
            out << "NO";

            in.close();
            out.close();
            return 0;
        }
    }

    out << "YES";

    in.close();
    out.close();
    return 0;
}
