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
	int ind, t;
	node(string &s, int &n) {
		int temp = 0, i = 1;
		if (s[0] == 'R') {
			ind = 0;
		}
		else ind = 1;
		while (s[i]) {
			temp = 10 * temp + (s[i++] - '0');
		}
		t = temp % n;
	}
};
vector<queue<node> > ss;
queue<node> m;
int main() {
	//这篇是抄的，思路太清晰了！！
	int T, n, t; cin >> T >> n;
	string s; getchar();
	stringstream sss;
	while (T--) {
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			sss << s;
			while (sss >> s) {
				m.push(node(s, n));
			}
			ss.push_back(m); sss.clear();
			while (!m.empty())m.pop();
		}
		while (1) {
			t = 0;
			for (int i = 0; i < n; i++) {
				if (ss[i].empty())continue;
				node k = ss[i].front();
				if (ss[k.t].empty())break;
				node h = ss[k.t].front();
				if ((h.ind + k.ind) != 1)continue;
				if (h.t != i)continue;
				ss[i].pop(); ss[k.t].pop();
				t++; i--;
			}
			if (!t)break;
		}
		for (int i = 0; i < n; i++) {
			if (!ss[i].empty()) { t = 1; break; }
		}
		if (!t)puts("0");
		else puts("1");
		while (!ss.empty())ss.pop_back();
	}
	sss.str("");
	return 0;
}