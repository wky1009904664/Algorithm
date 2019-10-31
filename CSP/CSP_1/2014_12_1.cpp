#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
int main(void)
{
	stringstream ss;
	int rec[1000] = { 0 };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		++rec[temp];
		ss << rec[temp];
		if (i != n - 1)
			ss << ' ';
	}
	cout << ss.str() << endl;
	return 0;
}