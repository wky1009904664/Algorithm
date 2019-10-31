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
	int a, b, c, y1, y2;
	int monthDay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	cin >> a >> b >> c >> y1 >> y2;
	int firstDay[205] = { 0 };
	firstDay[0] = 2;//Year 1850
	for (int i = 1; i < 205; i++) {
		int temp = isRun(i + 1849) ? 2 : 1;
		firstDay[i] = (firstDay[i - 1] + temp - 1) % 7 + 1;
	}
	int monthSum = 0;
	for (int i = 0; i < a - 1; i++)
		monthSum += monthDay[i];
	for (int i = y1 - 1850; i <= y2 - 1850; i++) {
		int ansday;
		if (isRun(i+1850)) {
			monthDay[1] = 29;
			if (a > 2)
				monthSum += 1;
		}
		int monthFirst = (firstDay[i] + monthSum - 1) % 7 + 1;
		if (monthFirst >= c)
			ansday = (8 + c - monthFirst-1)%7+1;
		else
			ansday = c - monthFirst + 1;
		ansday += (b - 1) * 7;
		if (ansday > monthDay[a-1])
			cout << "none" << endl;
		else {
			printf("%d/%02d/%02d\n", i + 1850, a, ansday);
		}
		if (isRun(i+1850)) {
			monthDay[1] = 28;
			if (a > 2)
				monthSum -= 1;
		}
	}

	return 0;
}