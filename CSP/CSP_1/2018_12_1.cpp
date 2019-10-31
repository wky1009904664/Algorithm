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

int main(void)
{	/*

	*/
	long long  r, y, g, n;
	cin >> r >> y >> g >> n;
	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == 0)
			res += b;
		else if (a == 1)
			res += b;
		else if (a == 2)
			res += b + r;
	}
	cout << res << endl;

	return 0;
}
