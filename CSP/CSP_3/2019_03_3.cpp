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
using ll = long long;

struct chunk {
	ll order;
	string str;
};

struct pai {
	ll dsk, blk;
};

struct disk {
	ll order;
	vector<chunk> bilks;
};
vector<disk>disks;

bool cmp(disk a, disk b) {
	return a.order < b.order;
}

ll tnum(char c) {
	if (c >= '0'&&c <= '9')
		return c - '0';
	else
		return c - 'A' + 10;
}

string yihuo(string a, string b)
{
	string res;
	for (ll i = 0; i < 8; i++) {
		ll temp = tnum(a[i]) ^ tnum(b[i]);
		if (temp <= 9)
			temp += '0';
		else
			temp += 'A' - 10;
		res += temp;
	}
	return res;
}


int main(void)
{	/*
		2个数是一个字节
	*/
	ios::sync_with_stdio(false);
	ll n, s, l;
	cin >> n >> s >> l;
	for (ll i = 0; i < l; i++) {
		ll ord; string str;
		disk d;
		cin >> ord;
		cin >> str;
		d.order = ord;
		ll siz = str.size() / 8;
		for(int j=0;j<siz;j++){
			chunk temp;
			temp.str = str.substr(j*8, 8);
			d.bilks.push_back(temp);
		}
		disks.push_back(d);
	}

	sort(disks.begin(), disks.end(), cmp);

	ll blkcon = disks[1].bilks.size();
	vector<vector<ll>> vec(n, vector<ll>(blkcon, 0));//disk,blk
	vector<pai> mp((n - 1)*blkcon);

	ll pn = n , con = blkcon / s;
	ll jishu = 0;
	for (ll i = 0; i < con; i++) {
		pn -= 1;
		if (pn == -1)
			pn = n - 1;
		for (ll h = 0; h < s; h++) {
			vec[pn][i*s + h]= -1;
		}
		for (ll j = 1; j < n; j++) {
			ll curr = (pn + j ) % n;
			for (ll h = 0; h < s; h++) {
				vec[curr][i*s + h] = jishu++;
				mp[jishu - 1].blk = i * s + h;
				mp[jishu - 1].dsk = curr;
			}
		}
	}

	ll m, c;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		cin >> c;
		ll bl = mp[c].blk;
		ll ds = mp[c].dsk;
		ll dskres = -1;
		for (ll j = 0; j < l; j++)
			if (disks[j].order == ds) {
				dskres = j;
				break;
			}
		if (dskres != -1) {//finded
			cout << disks[dskres].bilks[bl].str << endl;
		}
		else {
			if (n - l >= 2)
				cout << '-' << endl;
			else {
				string ans = disks[0].bilks[bl].str;
				for (ll j = 1; j < l; j++) {
					ans = yihuo(disks[j].bilks[bl].str, ans);
				}
				cout << ans << endl;
			}
		}

	}


	return 0;
}
