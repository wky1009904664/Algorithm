#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	string current;
	getline(cin, current);
	stringstream ans;
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		vector<string> res;
		if (str[0] != '/')
			str = current + '/' + str;
		if (str == "") {
			ans << current << endl;
			continue;
		}
		for (int j = 0; j < str.length(); j++)
			if (str[j] == '/') str[j] = ' ';
		stringstream ss(str);
		string temp;
		while (ss >> temp) {
			if (temp == "..") {
				if (!res.empty())
					res.pop_back();
			}
			else if (temp == ".")
				;
			else
				res.push_back(temp);
		}
		if (res.empty())
			ans << "/" ;
		for (int j = 0; j < res.size(); j++)
			ans << "/" << res[j];
		ans << endl;
	}
	cout << ans.str();
	return 0;
}