#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
#include<map>
using namespace std;
int main(void)
{
	string n;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n.length(); i++) {
		count += n[i] - '0';
	}
	cout << count << endl;

	return 0;
}