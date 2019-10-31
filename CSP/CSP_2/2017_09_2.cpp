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

vector<int> start[10600];
vector<int> ss[10600];
int n, k;
int findgou(int* gou) {
	for (int i = 0; i < n; i++)
		if (gou[i] == -1)
			return i;
}

int main(void)
{	/*

	*/
	
	cin >> n >> k;
	int* gou = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		gou[i] = i + 1;
	for (int i = 0; i < k; i++) {
		int w, s, c;
		cin >> w >> s >> c;
		start[s].push_back(w);
		ss[s + c].push_back(w);
	}
	for (int i = 0; i < 10600; i++) {
		sort(start[i].begin(), start[i].begin() + start[i].size());
		sort(ss[i].begin(), ss[i].begin() + ss[i].size());
	}
	for (int i = 0; i < 10600; i++) {
		if (!ss[i].empty()) {
			for (int j = 0; j < ss[i].size(); j++)
				gou[findgou(gou)] = ss[i][j];
		}
		if (!start[i].empty()) {
			for (int j = 0; j < start[i].size(); j++){
				for (int s = 0; s < n; s++) {
					if (gou[s] == start[i][j]) {
						gou[s] = -1;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << gou[i] << " ";
	return 0;
}

