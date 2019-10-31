#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
#include<map>
using namespace std;
char graph[100][100];
int m, n, q;
void Padding(int x, int y, char c) {
	if (x < 0 || x >= n || y < 0 || y >= m || graph[x][y] == '-' || graph[x][y] == '|' || graph[x][y] == '+' || graph[x][y] == c)
		return;
	graph[x][y] = c;
	Padding(x - 1, y, c);
	Padding(x + 1, y, c);
	Padding(x, y - 1, c);
	Padding(x, y + 1, c);
}

int main(void)
{
	cin >> m >> n >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			graph[i][j] = '.';
	for (int i = 0; i < q; i++) {//while(q--)
		int type;
		cin >> type;
		if (type == 0) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2)
				swap(x1, x2);
			if (y1 > y2)
				swap(y1, y2);
			if (x1 == x2) {
				for (int j = y1;j<=y2; j++) {
					if (graph[j][x1] == '-' || graph[j][x1] == '+')
						graph[j][x1] = '+';
					else
						graph[j][x1] = '|';
				}
			}
			else {
				for (int j = x1; j <= x2; j++) {
					if (graph[y1][j] == '|' || graph[y1][j] == '+')
						graph[y1][j] = '+';
					else
						graph[y1][j] = '-';
				}
			}
		}
		else {
			int x, y; char c;
			cin >> x >> y >> c;
			Padding(y, x, c);
		}
	}
	
	for (int i = n - 1; i >= 0;i--) {
		for (int j = 0; j < m; j++)
			cout << graph[i][j];
		cout << endl;
	}

	return 0;
}