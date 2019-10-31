#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;

struct number {
	int num;
	int time = 0;
};

bool cmp(number a, number b) {
	if (a.time == b.time)
		return a.num < b.num;
	else
		return a.time > b.time;
}
int main(void)
{
	number input[1005];
	for (int i = 0; i < 1005; i++) {
		input[i].num = i;
		input[i].time = 0;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		input[temp].time++;
	}
	sort(input, input + 1005, cmp);
	for (int i = 0; i < 1005; i++) {
		if (input[i].time == 0)
			break;
		cout << input[i].num << " " << input[i].time << endl;
	}
	return 0;
}