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

struct node {
	int v, cost;
	node(int vv = 0, int c = 0) { v = vv, cost = c; }
	// 优先队列将按距离从小到大排列
	friend bool operator<(node n1, node n2) { return n1.cost > n2.cost; }
};
struct edge {
	int v;
	int cost;
	edge(int vv = 0, int c = 0) { v = vv, cost = c; }
};

vector<edge>g[10005];
int n, m;
int disto[10005];
int costo[10005];
bool marked[10005];

void dijkstra(int s)
{
	for (int i = 0; i <= n; i++) {
		costo[i]=disto[i] = INT_MAX;
		marked[i] = false;
	}
	disto[s] = 0;
	costo[s] = 0;

	priority_queue<node> q;
	q.push(node(s, 0));
	marked[0] = true;
	while (!q.empty())
	{
		node temp = q.top();
		q.pop();
		if (!marked[temp.v]) {
			marked[temp.v] = true;
			for (int i = 0; i < g[temp.v].size();i++) {
				int u = g[temp.v][i].v;
				if (marked[u])
					continue;
				int costadd = g[temp.v][i].cost;
				int newdis = costadd + disto[temp.v];
				if (newdis < disto[u]) {
					disto[u] = newdis;
					costo[u] = costadd;//
					q.push(node(u, newdis));
				}
				if (disto[u] == newdis)//
					costo[u] = min(costadd, costo[u]);
			}
		}
	}
}

int main(void)
{	/*
		[10000][10000]这样的数组会爆内存
		Difstra算法
	*/
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, r;
		cin >> a >> b >> r;
		g[a].push_back(edge(b, r));
		g[b].push_back(edge(a, r));
	}
	dijkstra(1);
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		res += costo[i];
	}
	cout << res << endl;

	return 0;
}
