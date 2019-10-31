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

int main(void)
{	/*

	*/
	int n, m;
	cin >> n >> m;
	vector<int> stu;
	for (int i = 0; i < n; i++)
		stu.push_back(i+1);
	for (int i = 0; i < m; i++) {
		int num, dis, pos;
		cin >> num >> dis;
		for (pos = 0; pos < n; pos++)
			if (stu[pos] == num)
				break;
		stu.erase(stu.begin() + pos);
		stu.insert(stu.begin()+ pos + dis, num);
	}
	for (int i = 0; i < n; i++)
		cout << stu[i] << " ";
	cout << endl;
	return 0;
}
