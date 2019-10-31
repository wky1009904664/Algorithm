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
using ll = long long;
struct edge {
	ll x, y;
	ll val;
};

bool cmp(edge x, edge y) {
	return x.val < y.val;
}

vector<edge> edges;
ll par[500001];

ll findpar(ll x) {
	return par[x] == x ? x : par[x] = findpar(par[x]);//这句话很关键！！！
}

void merge(ll x, ll y) {
	par[findpar(y)] = findpar(x);
}


ll n, m, root;
int main(void)
{	/*
		这道题可以说是Kruskal算法模板了
	*/
	cin >> n >> m >> root;
	ll res;
	for (ll i = 0; i < m; i++) {
		edge temp;
		cin >> temp.x >> temp.y >> temp.val;
		edges.push_back(temp);
	}
	for (ll i = 0; i < n; i++)
		par[i] = i;
	sort(edges.begin(), edges.end(), cmp);
	ll cnt = 0;
	for (ll i = 0; i < m; i++)
	{
		ll x = edges[i].x;
		ll y = edges[i].y;
		x = findpar(x);
		y = findpar(y);
		if (x == y)
			continue;
		par[x] = y;
		++cnt;
		if (cnt == n - 1) {
			res = edges[i].val;
			break;
		}
	}
	cout << res << endl;
	return 0;
}
