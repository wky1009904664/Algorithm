#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<map>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;


int main(void)
{	/*

	*/
	int n;
	cin >> n;
	int arr[1005];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int dis = abs(arr[0] - arr[1]);
	int prev = arr[1];
	for (int i = 2; i < n; i++) {
		int now = arr[i];
		int nowdis = abs(now - prev);
		if (nowdis > dis)
			dis = nowdis;
		prev = arr[i];
	}
	cout << dis << endl;

	return 0;

}