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

int dis[1001][1001];
bool visited[1001][1001];
int n, m, k, d;
struct node {
	int x, y;
	int val;
	node(int _x, int _y) :x(_x), y(_y) {}
	node() {}
};
node dire[4] = { {0,1},{0,-1},{1,0},{-1,0} };

inline bool isok(int x,int y) {
	return (x > 0 && y > 0 && x <= n && y <= n & !visited[x][y]);
}

int main(void)
{	/*
		广度优先搜索，这里起点有多个，直接全加到初始队列里
	*/

	cin >> n >> m >> k >> d;
	queue<node> q;
	vector<node>custom;
	node temp;
	for (int i = 0; i < m; i++) {
		cin >> temp.x >> temp.y;
		q.push(temp);
		visited[temp.x][temp.y] = true;
		dis[temp.x][temp.y] = 0;
	}
	for (int i = 0; i < k; i++) {
		cin >> temp.x >> temp.y >> temp.val;
		custom.push_back(temp);
	}
	for (int i = 0; i < d; i++) {
		int tx, ty;
		cin >> tx >> ty;
		visited[tx][ty] = true;
	}

	while (!q.empty())
	{
		node p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			node other(p.x + dire[i].x, p.y + dire[i].y);
			if (isok(other.x, other.y)) {
				q.push(other);
				visited[other.x][other.y] = true;
				dis[other.x][other.y] = dis[p.x][p.y] + 1;
			}
		}
	}
	long long cost = 0;
	for (int i = 0; i < k; i++) {
		cost += dis[custom[i].x][custom[i].y] * custom[i].val;
	}
	cout << cost << endl;
	return 0;
}