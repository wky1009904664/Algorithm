#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<map>
#include<vector>
#include<queue>
#include<math.h>
#include<list>
using namespace std;
int n;
int num[4];
char oper[3];

int quick(int i) {
	char p = oper[i];
	if (p == 'x' || p == '/')
		return 2;
	else
		return 1;
}

int comp(int a, int b, char p) {
	if (p == 'x')
		return a * b;
	else if (p == '/')
		return a / b;
	else if (p == '+')
		return a + b;
	else
		return a - b;
}

int main(void)
{	/*

	*/
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		int res;
		for (int j = 0; j < 4; j++)
			num[j] = temp[2 * j] - '0';
		for (int j = 0; j < 3; j++)
			oper[j] = temp[2 * j + 1];
		if (quick(0) < quick(1)) {
			res = comp(num[1], num[2], oper[1]);
			if (quick(2) == 2) {
				res = comp(res, num[3], oper[2]);
				res = comp(num[0], res, oper[0]);
			}
			else {
				res = comp(num[0], res, oper[0]);
				res = comp(res, num[3], oper[2]);
			}
		}
		else {
			res = comp(num[0], num[1], oper[0]);
			if (quick(1) < quick(2)) {
				int t = comp(num[2], num[3], oper[2]);
				res = comp(res, t, oper[1]);
			}
			else {
				res = comp(res, num[2], oper[1]);
				res = comp(res, num[3], oper[2]);
			}
		}
		if (res == 24)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}
