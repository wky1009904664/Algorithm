#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;

int main(void)
{
	int count = 0;
	int n;
	int temp; int last = 1005;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp != last)
			count++;
		last = temp;
	}
	cout << count << endl;
	return 0;
}