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

struct edge {
	int x, y;
	int val;
};

bool cmp(edge x, edge y) {
	return x.val < y.val;
}

edge edges[1000001];
int par[1001];

int findpar(int x) {
	return par[x] == x ? x : par[x]=findpar(par[x]);
}

void merge(int x, int y) {
	par[findpar(y)] = findpar(x);
}

int main(void)
{	/*

	*/
	int n; long m;
	long long cost = 0;
	int x, y, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> edges[i].x >> edges[i].y >> edges[i].val;
	}
	for (int i = 0; i < n; i++)
		par[i] = i;
	sort(edges, edges + m, cmp);
	for (int i = 0; i < m; i++) {
		int x = edges[i].x;
		int y = edges[i].y;
		if (findpar(x) == findpar(y))
			continue;
		merge(x, y);
		cost += edges[i].val;
	}
	cout << cost << endl;
	return 0;
}