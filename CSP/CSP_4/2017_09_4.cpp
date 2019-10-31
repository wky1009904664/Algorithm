#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<map>
#include<vector>
#include<queue>
#include<math.h>
#include<list>
using namespace std;

vector<int> g[1005];
bool canre[1005][1005];
bool visited[1005];

void init() {
	for (int i = 0; i < 1005; i++)
		visited[i] = false;
}

void dfs(int s)
{
	visited[s] = true;
	for (int i = 0; i < g[s].size(); i++) {
		int v = g[s][i];
		if (!visited[v]) {
			
			dfs(v);
		}
	}
}

int main(void)
{	/*

	*/
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		init();
		dfs(i);
		for (int j = 1; j <= n; j++) {
			if (visited[j]) {
				canre[i][j] = true;
				canre[j][i] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		bool ok = true;
		for (int j = 1; j <= n; j++) {
			if (!canre[i][j]) {
				ok = false;
				break;
			}
		}
		if (ok)
			++cnt;
	}
	cout << cnt << endl;
	return 0;
}
