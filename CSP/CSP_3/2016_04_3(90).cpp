#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
#include<map>
#include<string.h>
using namespace std;

vector<string> split(const string& str, char div) {
	vector<string> res;
	char d[2];
	d[0] = div;
	d[1] = '/0';
	char* strs = new char[str.length() + 1];
	strcpy(strs, str.c_str());
	
	char* p = strtok(strs, d);
	while (p) {
		string s = p;
		res.push_back(s);
		p = strtok(NULL, d);
	}
	return res;
}

int main(void)
{
	int p;
	cin >> p;
	cin.ignore();
	string current;
	getline(cin, current);
	vector<string> curr = split(current, '/');
	stringstream ans;
	for (int h= 0; h < p; h++) {
		string temp;
		
		getline(cin, temp);
		if (temp == "") {
			ans << current << endl;
			continue;
		}
		if (temp[0] != '/')
			temp = current + '/' + temp;
		vector<string> path = split(temp,'/');

		vector<string> res;
		for (int i = 0; i < path.size(); i++) {
			if (path[i] == "..") {
				if (!res.empty())
					res.pop_back();
			}
			else if (path[i] == ".")
				;
			else
				res.push_back(path[i]);
		}	
		if (res.empty())
			ans << "/";
		for (int j = 0; j < res.size(); j++) {
			ans << "/" << res[j];
		}
		ans << endl;
	}
	cout << ans.str();

	return 0;
}