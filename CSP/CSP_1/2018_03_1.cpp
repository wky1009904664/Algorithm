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
	int score = 0;
	int con = 0;
	int n;
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		else if (n == 1) {
			score += 1;
			con = 0;
		}
		else {
			++con;
			score += 2 * con;
		}
	}
	cout << score << endl;
	return 0;
}