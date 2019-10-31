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

int mar[1001][1001];
int key[1001] = { 0 };
bool visited[1001] = { false };
int main(void)
{	/*

	*/
	int n; long m;
	long long cost = 0;
	int x, y, v;
	cin >> n >> m;
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)//1~1000
			mar[i][j] = INT_MAX;
	for (long i = 0; i < m; i++) {
		cin >> x >> y >> v;
		mar[x][y] = v;
		mar[y][x] = v;
	}
	for (int i = 0; i < 1001; i++)
		key[i] = INT_MAX;
	key[1] = 0;
	for (int i = 0; i < n; i++) {
		int mindis = INT_MAX;
		int minu = 10000;
		for (int j = 1; j <= n; j++) {
			if (!visited[j]&&key[j ] < mindis) {
				mindis = key[j];
				minu = j ;
			}
		}
		visited[minu] = true;
		for (int s = 1; s <= n; s++) {
			if (!visited[s] && key[s] > mar[s][minu])
				key[s] = mar[s][minu];
		}
	}
	for (int i = 1; i <= n; i++)
		cost += key[i];
	cout << cost << endl;

	return 0;
}