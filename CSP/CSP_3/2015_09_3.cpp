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
	int m, n;
	cin >> m>>n;
	string sent[100];
	map<string, string> var;
	cin.ignore();
	for (int i = 0; i < m; i++) {
		getline(cin, sent[i]);
	}

	for (int i = 0; i < n; i++) {
		string key;
		cin >> key;
		string value;
		getline(cin, value);
		var[key] = value.substr(2, value.length() - 3);
	}

	for (int i = 0; i < m; i++) {
		int prev = 0; int next;
		while (1) {
			if ((prev = sent[i].find("{{ ", prev)) == string::npos)
				break;
			if ((next = sent[i].find(" }}", prev)) == string::npos)
				break;
			string para = sent[i].substr(prev + 3, next - prev - 3);
			string value = var[para];
			sent[i].replace(prev, next - prev + 3, var[para]);
			prev += var[para].length();
		}
	}

	for (int i = 0; i < m; i++)
		cout << sent[i] << endl;

	return 0;
}