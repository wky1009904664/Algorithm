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

struct ip {
	int per[4] = { 0 };
	string ipstr;
	int len;
};
int pow2[] = { 1,2,4,8,16,32,64,128 };

list<ip> ips;

vector<int> split(string s)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '.' || s[i] == '/')
			s[i] = ' ';
	stringstream ss(s);
	vector<int> res;
	int temp;
	while (ss >> temp)
		res.push_back(temp);
	return res;
}

bool cmp(ip a, ip b)
{
	for (int i = 0; i < 4; i++) {
		if (a.per[i] != b.per[i])
			return a.per[i] < b.per[i];
	}
	return a.len < b.len;
}

void handleip(ip& p)
{
	string temp, res;
	for (int i = 0; i < 4; i++) {
		int a = p.per[i];
		if (a == 0)
			res += "00000000";
		else {
			for (int j = 7; j >= 0; j--) {
				if (a >= pow2[j]) {
					a -= pow2[j];
					res += '1';
				}
				else
					res += '0';
			}
		}
	}
	p.ipstr = res;
}

bool isson(ip a, ip b)
{
	if (a.len > b.len)
		return false;
	for (int i = 0; i < a.len; i++) {
		if (a.ipstr[i] != b.ipstr[i])
			return false;
	}
	return true;
}

bool canmerge2(ip a, ip b)
{
	if (a.len != b.len)
		return false;
	if (a.ipstr[a.len - 1] != '0')
		return false;
	for (int i = 0; i < a.len - 1; i++) {
		if (a.ipstr[i] != b.ipstr[i])
			return false;
	}
	return b.ipstr[a.len - 1] =='1';
}

void printip(ip a)
{
	for (int i = 0; i < 4; i++) {
		string temp = a.ipstr.substr(i*8, 8);
		int res = 0;
		for (int j = 0; j < 8; j++) {
			res += (temp[j] - '0')*pow2[7 - j];
		}
		cout << res;
		if (i != 3)
			cout << '.';
	}
	cout << '/' << a.len << endl;
}

int main(void)
{	/*

	*/
	long n; string line;
	cin >> n;
	cin.ignore();
	for (long i = 0; i < n; i++)
	{
		getline(cin, line);
		ip temp;
		vector<int> spl = split(line);
		int size = spl.size();
		auto t = line.find("/");
		if (t == string::npos) {
			for (int j = 0; j < size; j++)
				temp.per[j] = spl[j];
			temp.len = size * 8;
		}
		else {
			for (int j = 0; j < size - 1; j++)
				temp.per[j] = spl[j];
			temp.len = spl[size - 1];
		}
		handleip(temp);
		ips.push_back(temp);
	}
	//step 1
	//sort(ips.begin(), ips.end(), cmp);
	ips.sort(cmp);
	//step2
	auto i = ips.begin(); auto j = ips.begin();
	for (++j;j!=ips.end();)
	{
		if (isson(*i, *j)) {
			j=ips.erase(j);
		}
		else {
			++i;
			++j;
		}
	}
	//step3
	i = ips.begin();  j = ips.begin();
	for (++j; j!=ips.end();)
	{
		if (canmerge2(*i,*j)) {
			j = ips.erase(j);
			(*i).len -= 1;
			if (i != ips.begin()) {
				i--;
				j--;
			}
		}
		else {
			++i;
			++j;
		}
	}

	for (auto i = ips.begin(); i != ips.end(); i++)
		printip(*i);

	return 0;
}
