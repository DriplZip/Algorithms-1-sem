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
#include <regex> // regex_match(question, regex(".*str.*"))) // ищет в строке question слово str
#include <ctime>
#define module // число x // ans % x
#pragma comment(linker, "/STACK:2000000")

using namespace std;

int main()
{
	//ifstream in("input.txt");
	//ofstream out("output.txt");
	ifstream in("turtle.in");
	ofstream out("turtle.out");

	int h, w;
	in >> h >> w;

	vector<vector<int>> field(h, vector<int>(w, 0));

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			in >> field[i][j];

	for (int i = h - 2; i >= 0; i--)
		field[i][0] += field[i + 1][0];

	for (int i = 1; i < w; i++)
		field[h - 1][i] += field[h - 1][i - 1];

	for (int i = h - 2; i >= 0; i--)
		for (int j = 1; j < w; j++)
			field[i][j] = field[i][j] + max(field[i][j - 1], field[i + 1][j]);

	out << field[0][w - 1];

	in.close();
	out.close();
	return 0;
}