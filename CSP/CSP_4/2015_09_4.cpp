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

vector<int> node[10005];
bool visited[10005];
bool instak[10005];
int dfn[10005];
int low[10005];
long long time;
int res = 0;
vector<int> stak;

void tarjan(int u)
{
	dfn[u] = low[u] = ++time;
	stak.push_back(u);
	instak[u] = true;
	visited[u] = true;
	for (int i = 0; i < node[u].size(); i++) {
		int v = node[u][i];
		if (!visited[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (instak[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		int con = 0;
		while (1) {
			int p = stak.back();
			stak.pop_back();
			instak[p] = false;
			con++;
			if (p == u)
				break;
		}
		if (con != 0)
			res += con * (con - 1) / 2;
	}
}


int main(void)
{	/*

	*/
	int n, m;
	cin >> n >> m;
	time = 0;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
	}

	for (int i = 1; i < n; i++) {
		if (!visited[i])
			tarjan(i);
	}
	cout << res << endl;
	return 0;
}