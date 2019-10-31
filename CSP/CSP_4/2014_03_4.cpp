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

struct node {
	long long x, y;
	int cost = 0; int addnum = 0;
	bool isadd;
	node(long long xx, long long yy, bool a = false) :x(xx), y(yy), isadd(a) {}
};


int main(void)
{	/*
	广度优先搜索
	*/
	long long n, m, k, r;
	vector<node> nodes;
	cin >> n >> m >> k >> r;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		nodes.push_back(node(a, b));
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		nodes.push_back(node(a, b, true));
	}
	bool* visited = (bool*)malloc(sizeof(bool)*(m + n));
	for (int i = 0; i < m + n; i++)
		visited[i] = false;
	visited[0] = true;
	queue <int> q;
	q.push(0);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (t == 1)
			break;
		for (int i = 0; i < n + m; i++) {
			if (!visited[i] && (pow(nodes[i].x - nodes[t].x, 2) + pow(nodes[i].y - nodes[t].y, 2) <= r*r))
			{
				if (nodes[i].addnum == k)
					continue;
				visited[i] = true;
				nodes[i].cost = nodes[t].cost + 1;
				nodes[i].addnum = nodes[t].addnum + nodes[i].isadd ? 1 : 0;
				q.push(i);
			}
		}
	}
	cout << nodes[1].cost - 1 << endl;
	return 0;
}