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

int n, m;
bool vis[100005];
int dist[100005];

struct node {
	int v, c;
	node(int _v, int _c) :v(_v), c(_c) {}
	bool operator <(const node&a)const { return c > a.c; }
};

vector<node> g[100005];

void dijstra()
{
	priority_queue<node> pq;
	pq.push(node(1, 0));
	dist[1] = 0;
	while (!pq.empty()) {
		node temp = pq.top();
		pq.pop();
		int u = temp.v;
		if (vis[u])
			continue;
		vis[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v;
			int val = g[u][i].c;
			if (max(val, dist[u]) < dist[v]) {
				dist[v] = max(val, dist[u]);
				pq.push(node(v, dist[v]));
			}
		}
	}
}

int main(void)
{	/*

	*/
	for (long long  i = 0; i < 100001; i++)
		dist[i] = INT_MAX;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back(node(v, c));
		g[v].push_back(node(u, c));
	}

	dijstra();
	cout << dist[n] << endl;

	return 0;
}
