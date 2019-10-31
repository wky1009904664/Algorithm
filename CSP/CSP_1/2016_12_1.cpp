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
	int less = 0;
	int greater = 0;
	int n;
	int midnum = -1;
	int arr[1005];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		less = greater = 0;
		int mid = arr[i];
		for (int j = 0; j < n; j++) {
			if (arr[j] < mid)
				less++;
			else if (arr[j] > mid)
				greater++;
		}
		if (less == greater) {
			midnum = mid;
			break;
		}
	}
	cout << midnum << endl;
	return 0;
}