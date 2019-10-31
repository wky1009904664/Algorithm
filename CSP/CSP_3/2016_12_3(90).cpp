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

struct user {
	string name;
	map<string, int> power;
};

map<string, bool> allpower;
vector<user> character;
vector<user> users;

int main(void)
{	/*

	*/
	int p, r, u, q;
	cin >> p;
	for (int i = 0; i < p; i++) {
		string temp;
		cin >> temp;
		auto t = temp.find(":");
		if (t == string::npos)
			allpower[temp] = false;
		else {
			temp=temp.substr(0, t);
			allpower[temp] = true;
		}
	}
	cin >> r;
	for (int i = 0; i < r; i++) {
		user ch;int con;
		for (auto it = allpower.begin(); it != allpower.end(); it++)
			ch.power[it->first] = -1;
		cin >> ch.name; cin >> con;
		for (int j = 0; j < con; j++) {
			string temp;
			cin >> temp;
			auto t = temp.find(":");
			if (t == string::npos)
				ch.power[temp] = 0;
			else {
				int level = temp[temp.length() - 1] - '0';
				temp=temp.substr(0, t);
				ch.power[temp] = level;
			}
		}
		character.push_back(ch);
	}
	cin >> u;
	for (int i = 0; i < u; i++) {
		user us; int con;
		for (auto it = allpower.begin(); it != allpower.end(); it++)
			us.power[it->first] = -1;
		cin >> us.name; cin >> con;
		for (int j = 0; j < con; j++) {
			string temp;
			cin >> temp;
			for (int s = 0; s < character.size(); s++) {
				user ch = character[s];
				if (ch.name == temp) {
					for (auto it = ch.power.begin(); it != ch.power.end(); it++) {
						if (us.power[it->first] <it->second)
							us.power[it->first] = it->second;
					}
				}
			}
		}
		users.push_back(us);
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		string name; string para;
		cin >> name >> para;
		bool hasname = false;
		bool haspara = true;
		for (int j = 0; j < users.size(); j++) {
			if (name == users[j].name) {
				hasname = true;
				user us = users[j];
				auto t = para.find(":");
				string pa = para.substr(0, t);
				if (allpower.count(pa) == 0) {
					haspara = false;
					break;
				}
				if (t == string::npos)
				{
					if (!allpower[para]) {
						if (us.power[para] == -1)
							cout << "false" << endl;
						else
							cout << "true" << endl;
					}
					else {
						if (us.power[para] == -1)
							cout << "false" << endl;
						else
							cout << us.power[para] << endl;
					}
				}
				else
				{
					int level = para[para.length() - 1] - '0';
					if (us.power[pa] < level)
						cout << "false" << endl;
					else
						cout << "true" << endl;
				}
			}
		}
		if (!hasname)
			cout << "false" << endl;
		else if (!haspara)
			cout << "false" << endl;
	}


	return 0;
}