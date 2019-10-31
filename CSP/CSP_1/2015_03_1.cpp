#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;
int main(void)
{
	int m, n;
	cin >> m;
	cin >> n;
	int** mar = (int**)malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++)
		mar[i] = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> mar[i][j];
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++)
			cout << mar[j][i] << " ";
		cout << endl;
	}

	return 0;
}