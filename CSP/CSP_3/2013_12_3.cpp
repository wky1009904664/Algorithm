#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{//https://www.cnblogs.com/ariel-dreamland/p/9159207.html
	int amount;
	int minH = 10001;
	long long res = 0;
	cin >> amount;
	int input[1001];
	for (int i = 0; i < amount; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < amount; i++) {
		if (i < amount - 1 && input[i] <= input[i + 1])
			continue;
		minH = input[i];
		for (int j = i; j >= 0; j--) {
			minH = min(input[j], minH);
			res = max(res, (long long)minH*(i - j + 1));
			
		}
	}
	cout << res << endl;
}
