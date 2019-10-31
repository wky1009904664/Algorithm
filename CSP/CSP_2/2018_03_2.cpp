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
	int pos;
	int dire;
};

node ball[105];
int con[1005];

int main(void)
{	/*

	*/
	int n, l, t;
	cin >> n >> l >> t;
	node temp;
	for (int i = 0; i < n; i++) {
		cin >> ball[i].pos;
		++con[ball[i].pos];
		ball[i].dire = 1;
	}
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < n; j++) {
			--con[ball[j].pos];
			ball[j].pos += ball[j].dire;
			++con[ball[j].pos];
			if (ball[j].pos == l||ball[j].pos==0)
				ball[j].dire *= -1;
		}
		int colipos = -1;
		for (int c = 0; c <= l; c++) {
			if (con[c] == 2) {
				for (int s = 0; s < n; s++)
					if (ball[s].pos == c)
						ball[s].dire *= -1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << ball[i].pos << " ";
	return 0;
}