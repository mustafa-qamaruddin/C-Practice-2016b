//============================================================================
// Name        : ChrisandMagicSquare.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

typedef long long ull;

int main() {
	//freopen("tc.txt", "r", stdin);

	int missing_i, missing_j;
	int n;
	cin >> n;

	ull** grid = new ull*[n];

	for(int i = 0; i < n; i++)
	{
		grid[i] = new ull[n];
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++ )
		{
			ull temp;
			cin >> temp;
			if(!temp){
				missing_i = i;
				missing_j = j;
			}
			grid[i][j] = temp;
		}
	}

	ull row_sum = 0;

	// calculate full row sum
	for(int i = 0; i < n; i++)
	{
		if(i == missing_i)
			continue;
		row_sum = 0;
		for(int j = 0; j < n; j++)
		{
			row_sum += grid[i][j];
		}
	}

	// fill the empty cell
	ull incomplete_sum = 0;
	for(int j = 0; j < n; j++)
	{
		incomplete_sum += grid[missing_i][j];
	}

	ull missing_value = row_sum - incomplete_sum;
	grid[missing_i][missing_j] = missing_value;

	ull diag_sum = 0, second_diag_sum = 0;
	for(int i = 0; i < n; i++)
	{
		ull temp_sum = 0;
		for(int j = 0; j < n; j++)
		{
			temp_sum += grid[i][j];
			if(i == j)
				diag_sum+= grid[i][j];

			if(j == n-i-1)
			{
				second_diag_sum += grid[i][j];
			}
		}
		if(temp_sum != row_sum)
		{
			cout << -1;
			return(0);
		}
	}

	if(diag_sum != second_diag_sum || diag_sum != row_sum || second_diag_sum != row_sum)
	{
		cout << -1;
		return(0);
	}

	for(int j = 0; j < n; j++)
	{
		ull temp_sum = 0;

		for(int i = 0; i < n; i++)
		{
			temp_sum += grid[i][j];
		}

		if(temp_sum != row_sum)
		{
			cout << -1;
			return(0);
		}
	}

	if(n == 1 && grid[missing_i][missing_j]<=0)
		cout << 1;
	else if(grid[missing_i][missing_j]<=0)
		cout << -1;
	else
		cout << grid[missing_i][missing_j];
	return(0);
}
