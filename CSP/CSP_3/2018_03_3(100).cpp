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

string p[105], r[105], s;

bool match(string s, string t, string& res)//s,p[j],res
{
	int lens = s.size();
	int lent = t.size();
	bool lastend = (s[s.size() - 1] == t[t.size() - 1]);
	int ps = 0, pt = 0;
	while (ps < lens&&pt < lent)
	{
		if (s[ps] == t[pt]) {
			ps++, pt++;
		}
		else {
			if (t[pt++] != '<')
				return false;
			res += ' ';
			if (t[pt] == 'i') {
				bool ok = false;
				while (s[ps] && isdigit(s[ps])) {
					if (s[ps] != '0')
						ok = true;
					if (ok)
						res += s[ps];
					++ps;
				}
				if (!ok)
					return false;
				pt += 4;
			}
			else if (t[pt] == 's') {
				bool ok = false;
				while (s[ps] && s[ps] != '/') {
					ok = true;
					res += s[ps];
					++ps;
				}
				if (!ok)
					return false;
				pt += 4;
			}
			else if (t[pt] == 'p') {
				while (s[ps])
					res += s[ps++];
				return true;
			}
		}
	}
	return pt == lent && ps == lens;
}

int main(void)
{	/*

	*/
	int n, m;
	cin >> n >> m;
	string temp;
	for (int i = 0; i < n; i++)
		cin >> p[i] >> r[i];
	for (int i = 0; i < m; i++) {
		cin >> s;
		bool is404 = true;
		for (int j = 0; j < n; j++) {
			string res = r[j];
			if (match(s, p[j], res)) {
				cout << res << endl;
				is404 = false;
				break;
			}
		}
		if (is404)
			cout << 404 << endl;
	}

	return 0;
}