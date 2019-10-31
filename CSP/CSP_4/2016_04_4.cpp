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

bool visited[105][105][305];
int n, m, t;

struct node {
	int x, y;
	int dis;
};
queue<node> q;

struct dires {
	int x, y;
};
dires dire[] = { {-1,0},{1,0},{0,1},{0,-1} };

int bfs()
{
	node start, front, v;
	start.x = start.y = 1;
	start.dis = 0;
	q.push(start);
	while (!q.empty())
	{
		front = q.front();
		q.pop();
		if (front.x == n && front.y == m)
			return front.dis;
		for (int i = 0; i < 4; i++) {
			v.x = front.x + dire[i].x;
			v.y = front.y + dire[i].y;
			v.dis = front.dis + 1;
			if (v.x<1 || v.x>n || v.y<1 || v.y>m)
				continue;
			if (!visited[v.x][v.y][v.dis]) {
				q.push(v);
				visited[v.x][v.y][v.dis] = true;
			}
		}
	}
	return 0;
}

int main(void)
{	/*
		n和m，即x和y要搞清楚
		最好不要用x和y，容易混淆，用row和col代表行和列
		考点：变形的广度优先搜索，有3个维度的vistied数组
	*/
	cin >> n >> m >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = c; j <= d; j++)
			visited[a][b][j] = true;
	}
	int res = bfs();
	cout << res << endl;

	return 0;
}
