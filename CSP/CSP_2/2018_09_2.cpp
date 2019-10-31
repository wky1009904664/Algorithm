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

//long a[2005];
//long b[2005];
//long c[2005];
//long d[2005];
bool h[1000005];
bool w[1000005];
int main(void)
{	/*

	*/
	int n;
	cin >> n;
	/*for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	for (int i = 0; i < n; i++)
		cin >> c[i] >> d[i];*/
	int t1, t2;
	for (int i = 0; i < n; i++)
	{
		cin >> t1 >> t2;
		for (int j = t1; j < t2; j++)
			h[j] = true;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> t1 >> t2;
		for (int j = t1; j < t2; j++)
			w[j] = true;
	}
	int cou = 0;
	for (int i = 0; i < 1000005; i++) {
		if (h[i] == true && w[i] == true)
			cou++;
	}
	cout << cou << endl;
	return 0;
}