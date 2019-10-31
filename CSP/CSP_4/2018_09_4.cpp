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

int t, count;
int a[301], b[301];
bool f[301][301][301];
bool shouldstop = false;

void dfs(int n, int x, int y)
{
	if (f[n][x][y])
		return;
	if (shouldstop)
		return;
	f[n][x][y] = true;
	if (n == t - 1)
	{
		if ((3 * a[n] - x) / 2 == a[t] || (3 * a[n] - x + 1) / 2 == a[t] || (3 * a[n] - x + 2) / 2 == a[t]) //最后一天菜价 
		{
			/*for (int i = 1; i <= n; i++)
				cout << b[i] << " ";
			for (int i = 0; i < 3; i++) {
				if ((3 * a[i] - x + i) / 2 == a[t]) {
					cout << 3 * a[n] - x - y + i;
					shouldstop = true;
					return;
				}
			}*/
			for (int i = 1; i <= n; i++)
				cout << b[i] << " ";
			for (int i = 0; i < 3; ++i)
			{
				if ((3 * a[n] - x + i) / 2 == a[t]) {
					cout << 3 * a[n] - x - y + i;
					shouldstop = true;
					return;
				}
			}
		}
		return;
	}
	for (int i = 0; i < 3; ++i)
	{
		b[n + 1] = 3 * a[n] - x - y + i; //递推关系式 
		if (b[n + 1] >= 1)
			dfs(n + 1, y, b[n + 1]);
	}

}

int main(void)
{	/*
	https://blog.csdn.net/imotolove/article/details/82777819
	*/
	cin >> t;
	for (int i = 1; i <= t; ++i)
		cin >> a[i];
	for (int i = 1; i <= 2 * a[1]; ++i) {
		b[1] = i;
		b[2] = 2 * a[1] - i;
		dfs(2, i, b[2]);
		b[2] = 2 * a[1] - i + 1;
		dfs(2, i, b[2]);
	}
	return 0;
}
