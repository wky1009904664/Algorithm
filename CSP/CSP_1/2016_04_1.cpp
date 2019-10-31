#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int prev, next;
	int count = 0;
	bool isup = false;
	cin >> prev;
	for (int i = 0; i < n - 1; i++) {
		cin >> next;
		if (i > 0) {
			if (next < prev&&isup) {
				++count;
			}
			else if (next > prev && !isup) {
				++count;
			}
		}
		if (next > prev)
			isup = true;
		else
			isup = false;
		prev = next;
	}
	cout << count << endl;

	return 0;
}