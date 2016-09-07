#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long countAs(string s, int n)
{
    unsigned long long len = (unsigned long long)s.length();
    unsigned long long count_original = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == 'a')
            count_original++;
    }

    unsigned long long remainder = n % len;
    unsigned long long division = n / len;
    cout << "remainder:" << remainder << endl;
    cout << "division:" << division << endl;
    cout << "length:" << len << endl;
    unsigned long long ret = 0;
    for(int i = 0; i < remainder; i++)
    {
        if(s[i] == 'a')
            ret++;
    }

    return ret + division * count_original;
}

int main(){
    string s;
    cin >> s;
    long n;
    cin >> n;
    cout << countAs(s, n);
    return 0;
}
