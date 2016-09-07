//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* xs = new int[n];
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		xs[i] = temp;
	}

	sort(xs, xs+n);

	int median = (n-1)/2;
	cout << xs[median];
	return 0;
}
