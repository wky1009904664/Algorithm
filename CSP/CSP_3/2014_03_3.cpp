#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
int main(void)
{
	char sp[] = " ";
	int type[26] = { 0 };//0:empty 1:no_para 2:para
	string para[26];
	string firstLine;
	getline(cin, firstLine);
	for (int i = 0;i<firstLine.length(); i++) {
		if (firstLine[i] == ':')
			type[firstLine[i - 1] - 'a'] = 2;
		else
			type[firstLine[i] - 'a'] = 1;
	}
	int n;
	cin >> n;
	cin.ignore();
	stringstream res;
	for (int i = 0; i < n; i++) {
		string temp;
		getline(cin, temp);
		stringstream ss(temp);
		ss >> temp;
		while (ss >> temp) {//handle input
			if (temp[0] != '-')
				break;
			int ord = temp[1] - 'a';
			if (type[ord] == 0)
				break;
			else if (type[ord] == 1)
				para[ord] = " ";
			else
				ss >> para[ord];
		}
		
		res << "Case " << i +1<< ':';
		for (int j = 0; j < 26; j++) {
			if (type[j] != 0 && para[j] != "") {
				if (type[j] == 1)
					res << " -" << char(j + 'a');
				else {
					res << " -" << char(j + 'a') << ' ' << para[j];
				}
			}
			para[j] = "";
		}
		res << endl;
	}
	cout << res.str();

	return 0;
}
