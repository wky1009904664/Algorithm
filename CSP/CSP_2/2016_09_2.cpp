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
	int n;
	cin >> n;
	int arr[20];
	for (int i = 0; i < 20; i++)
		arr[i] = 5;
	stringstream ss;
	for (int i = 0; i < n; i++) {
		int temp;
		bool isTog = false;
		cin >> temp;
		for (int j = 0; j < 20; j++) {
			if (temp <= arr[j]) {
				for (int h = 0; h < temp; h++) {
					ss << to_string( j * 5 + 6 - arr[j] + h);
					ss << " ";
				}
				arr[j] -= temp;
				ss << endl;
				isTog = true;
				break;
			}
		}
		if (!isTog) {
			for (int s = 0; s < 20; s++) {
				if (arr[s] == 0)
					continue;
				if(arr[s]<=temp){
					for (int tt = 0; tt < arr[s]; tt++)
						ss << s * 5 + 6 - arr[s] + tt << " ";
					temp -= arr[s];
					arr[s] = 0;
				}
				else {
					for (int tt = 0; tt < temp; tt++)
						ss << s * 5 + 6 - arr[s] + tt << " ";
					arr[s] -= temp;
					break;
				}
			}
			ss << endl;
		}
	}
	cout << ss.str();
	return 0;
}