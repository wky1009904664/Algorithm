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
using ll = long long;
ll input[100005];
int main(void)
{	/*

	*/
	ll res[3];//max,mid,min
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> input[i];
	
	res[0] = input[n - 1];
	res[2] = input[0];
	bool ishalf = false;
	if (n % 2 == 1)
		res[1] = input[n/2];
	else {
		ll temp = input[n / 2] + input[n / 2 - 1];
		if (temp % 2 == 1)
			ishalf = true;
		res[1] = temp / 2;
	}
	sort(res, res + 3);
	cout << res[2] << " "<<res[1];
	if (ishalf)
		cout << ".5";
	cout <<" "<< res[0] << endl;
	return 0;
}
