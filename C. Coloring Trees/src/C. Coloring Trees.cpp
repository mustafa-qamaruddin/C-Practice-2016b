//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	freopen("tc_1.txt", "r", stdin);

	int n, m, k;
	cin >> n >> m >> k;

	int* trees_colors = new int[n];
	for(int i = 0; i < n; i++)
	{
		int temp_color;
		cin >> temp_color;
		trees_colors[i] = temp_color;
	}

	int** paint_litres = new int*[n];
	for(int i = 0; i < n; i++)
		paint_litres[i] = new int[m];

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int temp_p;
			cin >> temp_p;
			paint_litres[i][j] = temp_p;
		}
	}

	int**** dp = new int***[k];
	for(int i = 0; i < k; i++)
	{
		dp[i] = new int**[n];
		for(int j = 0; j < n; j++)
		{
			dp[i][j] = new int*[m];
			for(int l = 0; l < m; l++)
			{
				dp[i][j][l] = 0;
			}
		}
	}

	return 0;
}
