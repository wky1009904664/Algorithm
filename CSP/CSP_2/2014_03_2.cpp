#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main(void)
{
	int m, n;
	cin >> n;
	cin >> m;
	int win[10][5] = { 0 };
	int op[10][2] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++)
			cin >> win[i][j];
		win[i][4] = i+1;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++)
			cin >> op[i][j];
	}

	for (int i = 0; i < m; i++) {
		int j;
		for ( j =n-1; j >=0; j--) {
			if (op[i][0] >= win[j][0] && op[i][0] <= win[j][2] && op[i][1] >= win[j][1] && op[i][1] <= win[j][3]) {
				cout <<win[j][4]<< endl;
				for (int s = 0; s < 5; s++) {
					int temp = win[j][s];
					for (int h = j; h < n - 1; h++)
						win[h][s] = win[h+ 1][s];
					win[n - 1][s] = temp;
				}
				break;
			}
		}
		if (j == -1)
			cout << "IGNORED" << endl;
	}

	return 0;

}