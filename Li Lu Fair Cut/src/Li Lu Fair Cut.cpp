//============================================================================
// Name        : Li.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using namespace std;

int calcCost(int* arr, int len, bool* uf)
{
	cout << "Call Calculate Cost::" << endl;
	int ret = 0;

	for(int i = 0; i< len; i++)
	{
		if(uf[i] == true)
		{
			for(int j = 0; j < len; j++)
			{
				if(j == i || uf[i] == true)
					continue;

				ret += abs(arr[i] - arr[j]);
			}
		}
	}

	return ret;
}

int dp(int k, int index, int len, int* arr, bool* uf, int** mem)
{
	if(k == 0)
		return calcCost(arr, len, uf);

	if(index == len)
		return 0;

	if(mem[index][k] != -1){
		cout << "Memoization:" << endl;
		cout << "index:" << index << endl;
		cout << "k:" << k << endl;
		return mem[index][k];
	}

	uf[index] = true;
	int take = dp(k-1, index+1, len, arr, uf, mem);

	uf[index] = false;
	int no_take = dp(k, index+1, len, arr, uf, mem);

	mem[index][k] = min(take, no_take);

	cout << "Manifestation:" << endl;
	cout << "K=" << k << endl;
	cout << "Index=" << index << endl;
	cout << "Mem:" << endl;
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < k; j++)
		{
			cout << setw(5) << mem[i][j];
		}
		cout << endl;
	}

	return mem[index][k];
}

int main() {
	int n, k;
	int* arr;

	cin >> n >> k;
	arr = new int[n];

	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr[i] = temp;
	}

	int** mem = new int*[n];
	for(int i = 0; i < n; i++)
	{
		mem[i] = new int[k];
		for(int j = 0; j < k; j++)
		{
			mem[i][j] = -1;
		}
	}

	bool* uf = new bool[n];
	memset(uf, false, sizeof(bool));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			cout << setw(5) << mem[i][j];
		}
		cout << endl;
	}

	cout << dp(k, 0, n, arr, uf, mem);
	return 0;
}
