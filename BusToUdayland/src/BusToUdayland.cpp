//============================================================================
// Name        : BusToUdayland.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	char* seats = new char[n*5];
	bool can_sit = false;
	for(int i = 0;i < n; i++)
	{
		char temp_1, temp_2, temp_3, temp_4, temp_5;
		cin >> temp_1 >> temp_2 >> temp_3 >> temp_4 >> temp_5;

		seats[5*i+2] = temp_3;
		if(!can_sit && temp_1 == 'O' && temp_2 == 'O')
		{
			can_sit = true;
			seats[5*i+0] = '+';
			seats[5*i+1] = '+';
			seats[5*i+3] = temp_4;
			seats[5*i+4] = temp_5;
		}
		else if(!can_sit && temp_4 == 'O' && temp_5 == 'O')
		{
			can_sit = true;
			seats[5*i+0] = temp_1;
			seats[5*i+1] = temp_2;
			seats[5*i+3] = '+';
			seats[5*i+4] = '+';
		}
		else
		{
			seats[5*i+0] = temp_1;
			seats[5*i+1] = temp_2;
			seats[5*i+3] = temp_4;
			seats[5*i+4] = temp_5;
		}
	}

	if(can_sit)
	{
		cout << "YES" << endl;
		for(int i = 0; i < n; i++)
		{
			cout << seats[5*i]
						  << seats[5*i+1]
								   << seats[5*i+2]
											<< seats[5*i+3]
													 << seats[5*i+4];
			cout << endl;
		}
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
