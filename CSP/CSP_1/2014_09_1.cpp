#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main(void)
{
	int n;
	int  count = 0;
	cin >> n;
	int arr[10000] = { 0 };
	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;
		arr[in]++;
	}
	for (int i = 0; i < 10000; i++) {
		if (arr[i] != 0 && arr[i + 1] != 0)
			++count;
	}
	cout << count;
	return 0;
}