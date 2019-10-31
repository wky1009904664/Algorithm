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

long hou[2000];

int main(void)
{	/*

	*/
	long t;
	cin >> t;
	for (int i = 0; i < 2000; i++)
	{
		long qian = i * 100;
		
		if (qian < 3500) {
			hou[i] = qian;
			continue;
		}
		long a = qian - 3500;
		if (a <= 1500)
			hou[i] = qian - a * 0.03;
		else if (a <= 4500)
			hou[i] = qian - 1500 * 0.03 - (a - 1500)*0.1;
		else if (a <= 9000)
			hou[i] = qian - 1500 * 0.03 - 3000 * 0.1 - (a - 4500)*0.2;
		else if (a <= 35000)
			hou[i] = qian - 1500 * 0.03 - 3000 * 0.1 - 4500 * 0.2 - (a - 9000)*0.25;
		else if (a <= 55000)
			hou[i] = qian - 1500 * 0.03 - 3000 * 0.1 - 4500 * 0.2 - 26000 * 0.25 - (a - 35000)*0.3;
		else if (a <= 80000)
			hou[i] = qian - 1500 * 0.03 - 3000 * 0.1 - 4500 * 0.2 - 26000 * 0.25 - 20000 * 0.3 - (a - 55000)*0.35;
		else
			hou[i] = qian - 1500 * 0.03 - 3000 * 0.1 - 4500 * 0.2 - 26000 * 0.25 - 20000 * 0.3 - 25000 * 0.35 - (a - 80000)*0.45;
	}
	for(int i=0;i<2000;i++)
		if (hou[i] == t) {
			cout << i * 100 << endl;
			break;
		}

	return 0;
}