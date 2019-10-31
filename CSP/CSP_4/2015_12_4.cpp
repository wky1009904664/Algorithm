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

bool visited[10005][10005];
vector<int> graph[10005];
int p[10005], d[10005];
vector<int> stak;

int findset(int i)
{
	if (i == p[i])
		return i;
	else
		return p[i] = findset(p[i]);
}

void dfs(int u)
{
	for (int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if (!visited[u][v]) {
			visited[u][v] = true;
			visited[v][u] = true;
			dfs(v);
		}
	}
	stak.push_back(u);
}

int main(void)
{	/*

	*/
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		d[a]++; d[b]++;
		graph[a].push_back(b);
		graph[b].push_back(a);
		int x = findset(a);
		int y = findset(b);
		if (x != y)
			p[x] = y;
	}
	int cnt = 0, du = 0;
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
		if (i == p[i])
			cnt++;
		if (d[i] % 2 != 0)
			du++;
	}
	if (cnt != 1 || (du != 0&&du!=2) || (du == 2 && d[1] % 2 == 0))
		cout << -1 << endl;
	else {
		dfs(1);
		for (int i = stak.size() - 1; i >= 0; i--)
			cout << stak[i] << " ";
		cout << endl;
	}

	return 0;
}
