#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main(void)
{
	int pos[1000]; int neg[1000];
	for (int i = 0; i < 1000; i++) {
		pos[i] = neg[i] = 0;
	}
	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input < 0)
			++neg[-input];
		else
			++pos[input];
	}
	int res = 0;
	for (int i = 0; i < 1000; i++) {
		res += min(pos[i], neg[i]);
	}
	cout << res;
	return 0;
}