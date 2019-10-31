#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
int main(void)
{
	int n;
	int flag = 0; //0:¨J  1:¨L
	cin >> n;
	int martix[500][500];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> martix[i][j];

	for (int i = 0; i < n; i++) {
		if (flag == 0) {
			for (int j = 0; j <= i; j++) {
				cout << martix[i - j][j];//¨J
				cout << " ";
			}
		}
		else {
			for (int j = i; j >=0; j--) {
				cout << martix[i - j][j];//¨L
				cout << " ";
			}
		}
		flag = flag == 0 ? 1 : 0;
	}

	for (int i = 1; i < n; i++) {
		if (flag == 0) {//¨J
			for (int j = n-1; j >= i; j--) {
				cout << martix[j][n + i - 1 - j];
				cout << " ";
			}
		}
		else {//¨L
			for (int j = i; j <= n - 1; j++) {
				cout << martix[j][n + i - 1 - j];
				cout << " ";
			}
		}
		flag = flag == 0 ? 1 : 0;
	}
	return 0;
}