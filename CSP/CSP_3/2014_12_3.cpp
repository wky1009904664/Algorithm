#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;

struct stock {
		float price;
		long long num;
		int order;
	};
bool cmp(stock x, stock y) {
	return x.price < y.price;
}

int main(void)
{
	stringstream ss;
	vector<stock> buy;
	vector<stock> sell;
	string type;
	int order = 0;
	string input;
	while (getline(cin, input)) {
		if (input.length()==0)
					break;
		ss << input << endl;
		
	}
	while (ss >> type)
	{
		++order;
		stock temp;
		if (type == "buy") {
			ss >> temp.price;
			ss >> temp.num;
			temp.order = order;
			buy.push_back(temp);
		}
		else if (type == "sell") {
			ss >> temp.price;
			ss >> temp.num;
			temp.order = order;
			sell.push_back(temp);
			
		}
		else {
			int out;
			ss >> out;
			for (auto iter = buy.begin(); iter < buy.end(); iter++) {
				if (iter->order == out) {
					buy.erase(iter);
					break;
				}
			}
			for (auto iter = sell.begin(); iter < sell.end(); iter++) {
				if (iter->order == out) {
					sell.erase(iter);
					break;
				}
			}
		}

	}

	sort(buy.begin(), buy.end(), cmp);
	sort(sell.begin(), sell.end(), cmp);
	long long* buyRes = (long long*)malloc(sizeof(long long)*buy.size());
	long long* sellRes = (long long*)malloc(sizeof(long long)*sell.size());
	long long res = 0;
	for (int i = buy.size() - 1; i >= 0; i--) {
		res += buy[i].num;
		buyRes[i] = res;
	}
	res = 0;
	for (int i = 0; i < sell.size(); i++) {
		res += sell[i].num;
		sellRes[i] = res;
	}

	float ans1; long long ans2 = 0;
	for (int i = 0; i < buy.size(); i++) {
		int j;
		for (j = sell.size() - 1; j >= 0; j--)
			if (sell[j].price <= buy[i].price)
				break;
		if (j != -1) {
			long long tempans = buyRes[i] > sellRes[j] ? sellRes[j] : buyRes[i];
			if (ans2 <= tempans) {
				ans2 = tempans;
				ans1 = buy[i].price;
			}
		}

	}

	printf("%.2f ", ans1);
	cout << ans2;
	return 0;
}

