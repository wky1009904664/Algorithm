#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<map>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

int main(void)
{	/*

	*/
	int n;
	cin >> n;
	n = n / 10;
	int song2 = n / 5;
	int song1 = (n % 5) / 3;
	int res = song2 * 7 + song1 * 4 + (n % 5) % 3;
	cout << res << endl;
	return 0;
}

