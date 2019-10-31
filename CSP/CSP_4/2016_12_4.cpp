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

int num[1005]; int sum[1005];
int dp[1005][1005];
int p[1005][1005];

int main(void)
{	/*
		n<1000,ti<10000
		平行四边形优化：p[i][j-1]<=p[i][j]<=p[i+1]
	*/
	int n;
	cin >> n;
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		sum[i] = sum[i - 1] + num[i];
		dp[i][i] = 0;
		p[i][i] = i;
	}
	//dp
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			dp[i][j] = INT_MAX;
			for (int k = p[i][j - 1]; k <= p[i + 1][j]; k++) {
				int val = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
				if (dp[i][j] > val) {
					dp[i][j] = val;
					p[i][j] = k;
				}
			}
		}
	}
	cout << dp[1][n] << endl;

	return 0;
}
