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

struct servant {
	int hp;
	int atk;
};

int main(void)
{	/*

	*/
	int hp[2];
	bool shouldStop = false;
	int res = 0;
	hp[0] = 30; hp[1] = 30;
	vector<servant> servs[2]{ vector<servant>(),vector<servant>() };
	int pla = 0;//0是先手，1是后手
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		string temp;
		cin >> temp;
		if (temp == "summon") {
			int pos;
			cin >> pos;
			servant ser;
			cin >> ser.atk >> ser.hp;
			//servs[pla].insert(servs[pla].begin() + pos - 1, ser);
			//servs[pla].push_back(ser);
			if (pos == servs[pla].size() + 1)
				servs[pla].push_back(ser);
			else
				servs[pla].insert(servs[pla].begin() + pos - 1, ser);
		}
		else if (temp == "end") {
			pla = 1 - pla;
		}
		else {//attack
			int plb = 1 - pla;
			int posa, posb;
			cin >> posa>>posb;
			if (posb != 0) {
				posa--;
				posb--;
				servs[pla][posa].hp -= servs[plb][posb].atk;
				servs[plb][posb].hp -= servs[pla][posa].atk;
				if (servs[pla][posa].hp <= 0)
					servs[pla].erase(servs[pla].begin()+posa );
				if (servs[plb][posb].hp <= 0)
					servs[plb].erase(servs[plb].begin() + posb );
			}
			else {
				hp[plb] -= servs[pla][posa - 1].atk;
				if (hp[plb] <= 0) {
					if (plb == 1)
						res = 1;
					else if (plb == 0)
						res = -1;
					shouldStop = true;
				}
			}
		}
		if (shouldStop)
			break;
	}

	cout << res << endl;
	cout << hp[0] << endl;
	cout << servs[0].size() << " ";
	for (int i = 0; i < servs[0].size(); i++)
		cout << servs[0][i].hp << " ";
	cout <<endl<< hp[1] << endl;
	cout << servs[1].size() << " ";
	for (int i = 0; i < servs[1].size(); i++)
		cout << servs[1][i].hp << " ";
	cout << endl;

	return 0;
}