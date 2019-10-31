#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<map>
#include<vector>
using namespace std;
int main(void)
{	/*
	0: 2
	1: 0,2
	2: 2,3
	3: 0,1,2
	4: 0,2,3
	5: all
	sta[i][j] : i代表的是当前处理的数字有i位，j指的是第j种情况的数量，用动态规划处理
	*/
	long long mod = 1000000007;
	int n;
	cin >> n;
	long long** sta = new long long*[n + 1];
	for (int i = 0; i < n + 1; i++)
		sta[i] = new long long[6];
	for (int i = 0; i < 6; i++)
		sta[0][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		sta[i][0] = 1;//only 2
		sta[i][1] = (sta[i - 1][0] + sta[i - 1][1] * 2) % mod;
		sta[i][2] = (sta[i - 1][0] + sta[i - 1][2]) % mod;
		sta[i][3] = (sta[i - 1][1]+sta[i-1][3]*2) % mod;
		sta[i][4] = (sta[i - 1][1] + sta[i - 1][2]+sta[i-1][4]*2) % mod;
		sta[i][5] = (sta[i - 1][3] + sta[i - 1][4] + sta[i - 1][5] * 2) % mod;
	}
	cout << sta[n][5] << endl;

	return 0;
}