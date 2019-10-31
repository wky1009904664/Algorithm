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

map<string, string> mp;

void format(string &s)
{
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '\\')
			s.erase(s.begin() + i);
	}
}

void deal(string &json, string& farther)
{
	string key, value;
	for (int i = 0; i < json.length(); i++)
	{
		if (json[i] == '"')
		{
			auto t = json.find(":", i + 1);
			key= json.substr(i + 1, t - i - 2);
			if (farther != "")
				key = farther + '.' + key;
			++t;
			while (json[t] == ' ')
				++t;
			if (json[t] == '"')
			{//str:str
				auto t2 = json.find(",", t + 1);
				if (t2 == string::npos)
					i = json.length() - 1;
				else
					i = t2;
				value = json.substr(t + 1, i - t - 2);
				format(key);
				format(value);
				
			}
			else
			{
				int count = 1;
				int t2 = t + 1;
				while (count != 0) {
					if (json[t2] == '{')
						++count;
					if (json[t2] == '}')
						--count;
					++t2;
				}
				i = t2;
				value = json.substr(t, t2 - t);
				deal(value, key);
				
			}
			mp[key] = value;
		}
	}
}

int main(void)
{	/*
		整体思路是递归处理json字符串
	*/
	int n, m;
	cin >> n >> m;
	cin.ignore();
	string input, json;
	for (int i = 0; i < n; i++) {
		getline(cin, input);
		for (auto it = input.begin(); it != input.end();) {
			if (isspace(*it))
				it = input.erase(it);
			else
				++it;
		}
		json += input;
	}
	string space = "";
	deal(json, space);
	for (int i = 0; i < m; i++) {
		getline(cin, input);
		if (mp.find(input) == mp.end())
			cout << "NOTEXIST" << endl;
		else {
			if (mp[input][0] == '{')
				cout << "OBJECT" << endl;
			else
				cout << "STRING " << mp[input] << endl;
		}
	}
	return 0;
}