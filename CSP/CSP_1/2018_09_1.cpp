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

int arr[1005];

int main(void)
{	/*

	*/
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int newarr[1005];
	for (int i = 1; i < n - 1; i++)
		newarr[i] = (arr[i - 1] + arr[i] + arr[i + 1]) / 3;
	newarr[0] = (arr[0] + arr[1]) / 2;
	newarr[n - 1] = (arr[n - 1] + arr[n - 2]) / 2;
	for (int i = 0; i < n; i++)
		cout << newarr[i] << " ";
	cout << endl;

	return 0;
}