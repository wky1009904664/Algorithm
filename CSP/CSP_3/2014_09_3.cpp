#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

int main(void)
{
	stringstream res;
	string s;
	getline(cin, s);
	int isSen;
	cin >> isSen;
	int n;
	cin >> n;
	if (isSen == 0)
		for (int i = 0; i < s.length(); i++)
			s[i] = toupper(s[i]);
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string temp;
		getline(cin, temp);
		string beifen = temp;
		if (isSen == 0)
			for (int j = 0; j < temp.length(); j++)
				temp[j] = toupper(temp[j]);
		auto ans = temp.find(s);
		if (ans != s.npos)
			res << beifen << endl;
	}

	cout << res.str();

	return 0;
}

