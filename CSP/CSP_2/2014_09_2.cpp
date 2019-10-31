#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int arr[100][100] = { 0 };
	int input[4];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++)
			cin >> input[j];
		for (int m = input[0]; m < input[2]; m++)
			for (int n = input[1]; n < input[3]; n++)
				arr[m][n] = 1;
	}
	int count = 0;
	for(int i=0;i<100;i++)
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] != 0)
				++count;
		}
	cout << count << endl;
	return 0;
}