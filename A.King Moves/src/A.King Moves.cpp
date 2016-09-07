//============================================================================
// Name        : King.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	char x;
	int y;
	cin >> x >> y;

	int ret = 8;

	if((x == 'a' || x == 'h') && (y == 1 || y == 8))
		ret -= 5;
	else if(x == 'a' || x == 'h')
		ret -= 3;
	else if(y == 1 || y == 8)
		ret -= 3;

	cout << ret;
	return(0);
}
