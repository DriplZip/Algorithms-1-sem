#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#define SELECTION_ACCURACY 0.000000000001 //  40 * 10 ~ binsearch  * n * n ~~ 2 sec

using namespace std;

bool checkB(vector<double> &lamps, double tempHeight)
{
	lamps[1] = tempHeight;

	for (int i = 2; i < lamps.size(); i++)
	{
		lamps[i] = 2.0 * lamps[i - 1] + 2.0 - lamps[i - 2];

		if (lamps[i] < 0.0)
		{
			return false;
		}
	}

	return true;
}

void binSearch(vector<double> &lamps, double left, double right)
{
	while (right - left > SELECTION_ACCURACY)
	{
		double mid = (right + left) / 2.0;

		if (checkB(lamps, mid))
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
}

int main()
{
	ifstream in("garland.in");
	ofstream out("garland.out");

    int n;
	in >> n;

    vector<double> lamps(n);

	double a;
	in >> a;

    lamps[0] = a;

	binSearch(lamps, 0.0, a);

	out << fixed << setprecision(2) << lamps[n - 1];

    in.close();
    out.close();
	return 0;
}