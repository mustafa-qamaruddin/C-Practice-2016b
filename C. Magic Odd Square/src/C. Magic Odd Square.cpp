//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	int odd = 1, even = 2, median = n/2 + 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			bool within_diamond = (abs(median-i)+abs(median-j) <= n/2);
			if(within_diamond)
			{
				cout << odd;
				odd += 2;
			} else {
				cout << even;
				even += 2;
			}
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}
