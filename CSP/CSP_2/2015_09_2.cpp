#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;

bool isRun(int i) {
	return (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0));
}

int main(void)
{
	int year, day;
	cin >> year >> day;
	int monthDay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isRun(year))
		monthDay[1] = 29;
	int sumday = 0; int i;
	for (i = 0; i < 12; i++) {
		sumday += monthDay[i];
		if (sumday >= day)
			break;
	}
	cout << i + 1 << endl;
	sumday -= monthDay[i];
	cout << day - sumday << endl;
		
	return 0;
}