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

struct node {
	vector<int> son;
	string name;
	string para = "";
	int fat = 0;
	int level;

	node() = default;
	node(string _name) :name(_name) {}
};

vector<node> css;

vector<string> split(string line) {
	stringstream ss(line);
	vector<string> res;
	string temp;
	while (ss >> temp)
		res.push_back(temp);
	return res;
}

string toup(string s) {
	string news = s;
	for (int i = 0; i < s.size(); i++)
		news[i] = toupper(s[i]);
	return news;
}

int main(void)
{	/*
		注意是否大小写区分！！！！！
	*/
	stringstream resss;
	int n, m;
	cin >> n >> m;
	cin.ignore();
	string line;
	getline(cin, line);
	node root(toup(line));
	root.level = 0;
	css.push_back(root);
	for (int i = 1; i < n; i++) {
		getline(cin, line);
		node temp;
		int p = 0, level;
		while (line[p] == '.')
			++p;
		temp.level = p / 2;
		auto t = line.find("#", p);
		if (t != string::npos) {
			temp.para = line.substr(t + 1);
			temp.name = toup(line.substr(p, t - p - 1));
		}
		else
			temp.name = toup(line.substr(p));
		//handel far&son
		for (int j = i - 1; j >= 0; j--) {
			if (temp.level == css[j].level) {
				temp.fat = css[j].fat;
				break;
				//css[css[j].fat].son.push_back(i);
			}
			else if (temp.level > css[j].level) {
				temp.fat = j;
				break;
			}
		}
		css.push_back(temp);
	}

	for (int i = 0; i < m; i++)
	{
		int rescount = 0;
		vector<int> res;
		getline(cin, line);
		vector<string> chos = split(line);
		if (chos.size() == 1)
		{
			for (int j = 0; j < n; j++) {
				if (line[0] == '#') {
					string para = line.substr(1);
					if (css[j].para == para) {
						++rescount;
						res.push_back(j + 1);
					}
				}
				else {
					string lines = toup(line);
					if (css[j].name == lines) {
						++rescount;
						res.push_back(j + 1);
					}
				}
			}
		}
		else
		{
			int matchs = chos.size();
			int pm = 0, pt = 0;//下面，上面
			while (pm != matchs - 1 && pt != n - 1) {
				if (chos[pm][0] == '#') {
					string pa = chos[pm].substr(1);
					if (pa == css[pt].para) {
						++pm; ++pt;
					}
					else
						++pt;
				}
				else {
					string sss = toup(chos[pm]);
					if (sss == css[pt].name) {
						++pm; ++pt;
					}
					else
						++pt;
				}
			}
			if (pm == matchs - 1) {//ok
				for (int s = pt; s < n; s++) {
					if (chos[pm][0] == '#') {
						string pa = chos[pm].substr(1);
						if (pa == css[s].para) {
							rescount++;
							res.push_back(s + 1);
						}
					}
					else {
						string sss = toup(chos[pm]);
						if (sss == css[s].name) {
							rescount++;
							res.push_back(s + 1);
						}
					}
				}
			}
		}
		resss << rescount;
		for (int h = 0; h < rescount; h++)
			resss << " " << res[h];
		resss << endl;
	}
	cout << resss.str() << endl;

	return 0;
}


//11 6
//html
//..head
//....title
//..body
//....h1
//....p #subtitle
//....div #main
//......h2
//......p #one
//......div
//........p #two
//div P
//P
//t #one
//#subtitle
//H1
//div #One #two
