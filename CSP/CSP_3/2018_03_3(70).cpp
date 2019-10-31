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

vector<string> split(string s) {
	vector<string> vec;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '/')
			s[i] = ' ';
	stringstream ss(s);
	string temp;
	while (ss >> temp)
		vec.push_back(temp);
	return vec;
}

bool isnum(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i]<'0'||s[i]>'9')
			return false;
	}
	return true;
}

long long tonum(string s) {
	stringstream ss(s);
	long temp;
	ss >> temp;
	return temp;
}

struct urlRule {
	vector<string> rule;
	string str;
	bool end;
};

urlRule ur[105];

int main(void)
{	/*

	*/
	int n, m;
	cin >> n >> m;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp[temp.size() - 1] == '/')
			ur[i].end = true;
		else
			ur[i].end = false;
		ur[i].rule = split(temp);
		cin >> temp;
		ur[i].str = temp;
	}
	
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		bool isend = (temp[temp.size() - 1] == '/');
		bool change = false;
		bool is404 = true;
		if (temp[temp.size() - 1] != '/') {
			temp += '/';
			change = true;
		}
		for (int j = 0; j < n; j++)
		{
			bool lastfit = (isend == ur[j].end);
			
			auto rule = ur[j].rule;
			bool canfit = true;
			string::size_type pos1,pos2=0;
			string para="";//long output para
			for (int s = 0; s < rule.size(); s++) {
				string frag;
				pos1 = pos2;
				pos2 = temp.find("/", pos1+1);
				if (pos2 == string::npos) {
					canfit = false;
					break;
				}
				if (rule[s] == "<int>") {
					frag = temp.substr(pos1 + 1, pos2 - pos1 - 1);
					if (isnum(frag))
						para += to_string(tonum(frag)) + ' ';
					else {
						canfit = false;
						break;
					}
				}
				else if (rule[s] == "<str>") {
					frag = temp.substr(pos1 + 1, pos2 - pos1 - 1);
					para += frag + ' ';
				}
				else if (rule[s] == "<path>") {
					frag = temp.substr(pos1 + 1);
					if (change)
						frag.pop_back();
					para += frag + ' ';
					pos2 = temp.size() - 1;
					lastfit = true;
					break;
				}
				else {
					frag = temp.substr(pos1 + 1, pos2 - pos1 - 1);
					if (rule[s] != frag) {
						canfit = false;
						break;
					}
				}
			}
			if ( canfit && lastfit ) {

				cout << ur[j].str << " " << para << endl;
				is404 = false;
			}
		}
		if (is404)
			cout << "404" << endl;
	}

	return 0;
}