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
//typedef long long int;
struct edge {
	int x, y;
	int val;
};

bool cmp(edge x, edge y) {
	return x.val < y.val;
}

vector<edge> edges;
int par[100001];

int findpar(int x) {
	return par[x] == x ? x :par[x]= findpar(par[x]);//这句话很关键！！！
}

void merge(int x, int y) {
	par[findpar(y)] = findpar(x);
}


int n, m;
int main(void)
{	/*
		自己写的超时了，85分
		findpar一定要这么写，否则会超时
	*/
	cin >> n >> m;
	int res;
	for (int i = 0; i < m; i++) {
		edge temp;
		cin >> temp.x >> temp.y >> temp.val;
		edges.push_back(temp);
	}
	for (int i = 0; i < n; i++)
		par[i] = i;
	sort(edges.begin(),edges.end(), cmp);
	for (int i = 0; i < m; i++)
	{
		int x = edges[i].x;
		int y = edges[i].y;
		x = findpar(x);
		y = findpar(y);
		if (x==y)
			continue;
		par[x] = y;
		if (findpar(1) == findpar(n)) {
			res = edges[i].val;
			break;
		}
	}
	cout << res << endl;
	return 0;
}
