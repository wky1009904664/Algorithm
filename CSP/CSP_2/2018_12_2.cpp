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
	long long time = 0;
	long long cycle = r + y + g;
	for (int i = 0; i < n; i++)
	{
		long a, b;
		long temp = 0;
		cin >> a >> b;
		if (a == 0)
			time += b;
		else {
			if (a == 1)
				temp = r - b;
			else if (a == 2)
				temp = cycle - b;
			else if (a == 3)
				temp = r + g - b;
			temp = (temp + time) % cycle;
			if (temp <= r)
				time += r - temp;
			else if (temp <= r + g)
				time += 0;
			else
				time += cycle - temp + r;
		}
	}
	cout << time << endl;

	return 0;
}
