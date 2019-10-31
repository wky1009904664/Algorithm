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


int main(void)
{	/*

	*/
	int n, k;
	int res = 1;
	cin >> n >> k;
	int ai[1005];
	for (int i = 0; i < n; i++)
		cin >> ai[i];
	int temp = 0;
	for (int i = 0; i < n; i++) {
		temp += ai[i];
		if (temp >= k) {
			if (i != n - 1)
				res++;
			temp = 0;
		 }
	}
	cout << res << endl;
	return 0;
}

