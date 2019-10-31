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

int tonum(string s)
{
	int res;
	stringstream ss;
	ss << s;
	ss >> res;
	return res;
}

string months[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
string weekday[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

int main(void)
{	/*
		<minutes><hours><day of month><month><day of week><command>
	*/
	int n;
	string s, t;//yyyy mm dd HH MM
	cin >> n >> s >> t;



	return 0;
}