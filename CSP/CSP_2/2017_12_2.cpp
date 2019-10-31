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

int main(void)
{	/*

	*/
	int n, k;
	cin >> n >> k;
	vector<int> kids;
	long count = 0; 
	for (int i = 0; i < n; i++)
		kids.push_back(i + 1);
	auto it = kids.begin();
	while (n != 1)
	{
		++count;
		if (count%k == 0||count%10==k) {
			it = kids.erase(it);
			if (it == kids.end())
				it = kids.begin();
			n--;
		}
		else {
			if (it == kids.end() - 1)
				it = kids.begin();
			else
				++it;
		}

	}
	cout << kids.front() << endl;
	return 0;
}