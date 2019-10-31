#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
#include<map>
using namespace std;
int main(void)
{
	int n, m;
	cin >> n >> m;
	/*int** mar = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
		mar[i] = (int*)malloc(sizeof(int)*m);
	int** isDis = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
		isDis[i] = (int*)malloc(sizeof(int)*m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			isDis[i][j] = 0;*/
	int mar[30][30];
	int isDis[30][30];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			isDis[i][j] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mar[i][j]; 

	for (int i = 0; i < n; i++) {
		int retime = 1;
		int prev = 11;
		for (int j = 0; j < m; j++) {
			if (mar[i][j] == prev) {
				retime++;
				if (j == m - 1 && retime >= 3) {
					for (int s = 0; s < retime; s++)
						isDis[i][j - s] = 1;
				}
			}
			else {
				if (retime >= 3) {
					for (int s = 1; s <= retime; s++)
						isDis[i][j-s] = 1;
					
				}
				prev = mar[i][j];
				retime = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int retime = 1;
		int prev = 11;
		for (int j = 0; j < n; j++) {
			if (mar[j][i] == prev) {
				retime++;
				if (j == n - 1 && retime >= 3) {
					for (int s = 0; s < retime; s++)
						isDis[j - s][i] = 1;
				}
			}
			else {
				if (retime >= 3) {
					for (int s = 1; s <= retime; s++)
						isDis[j-s][i] = 1;
				}
				prev = mar[j][i];
				retime = 1;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (isDis[i][j] == 0)
				cout << mar[i][j] << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}
	return 0;
}