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
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int mindis =INT_MAX;
	for (int i = 1; i < n; i++) {
		int temp = arr[i] - arr[i - 1];
		if (temp < mindis)
			mindis = temp;
	}
	cout << mindis << endl;

	return 0;
}

