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

vector<int> graph[20005];
int dis[20005];
bool visited[20005];

int main(void)
{	/*
		Ê÷µÄÖ±¾¶
	*/
	int n, m, temp;
	cin >> n >> m;
	dis[1] = 0;
	for (int i = 2; i <= m; i++) {
		cin >> temp;
		graph[temp].push_back(i);
		graph[i].push_back(temp);
		dis[i] = dis[temp] + 1;
	}
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		graph[temp].push_back(i + m);
		graph[i + m].push_back(temp);
		dis[i+m] = dis[temp] + 1;
	}
	int max = 0; int maxi;
	for (int i = 1; i <= m + n; i++) {
		if (dis[i] > max) {
			max = dis[i];
			maxi = i;
		}
	}
	for (int i = 0; i < 20005; i++)
		dis[i] = INT_MAX;
	dis[maxi] = 0;
	queue<int> q;
	q.push(maxi);
	visited[maxi] = true;
	max = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i = 0; i < graph[p].size(); i++) {
			int v = graph[p][i];
			if (!visited[v]) {
				dis[v] = dis[p] + 1;
				if (dis[v] > max)
					max = dis[v];
				visited[v] = true;
				q.push(v);
			}
		}
	}
	cout << max << endl;
	return 0;
}