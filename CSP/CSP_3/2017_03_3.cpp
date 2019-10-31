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

string findattr(string line) {
	string::size_type pos = 0;
	while ((pos = line.find("_", pos)) != string::npos) {
		line.replace(pos, 1, "<em>");
		pos = line.find("_", pos + 1);
		line.replace(pos, 1, "</em>");
		pos++;
	}
	return line;
}

string findlink(string line) {
	string::size_type pos = 0;
	while ((pos = line.find("[", pos)) != string::npos) {
		auto pos2 = line.find("]", pos + 1);
		auto temp = pos;
		string text = line.substr(pos + 1, pos2 - pos - 1);
		pos = pos2 + 2;
		pos2 = line.find(")", pos);
		string link = line.substr(pos, pos2 - pos);
		string ss = "<a href=\"" + link + "\">" + text + "</a>";
		line.replace(temp, pos2 - temp + 1, ss);
	}
	return line;
}

int main(void)
{	/*

	*/
	string line;
	stringstream ss;
	int flag = 0;//1是标题，2是无序列表，3是段落，4是
	while (getline(cin, line))
	{
		if (line == "")
		{
			if (flag == 2)
				ss << "</ul>" << endl;
			else if (flag == 3)
				ss << "</p>" << endl;
			flag = 0;
		}
		else 
		{
			//找强调
			line = findattr(line);
			//找超链接
			line = findlink(line);
			if (line[0] == '#')
			{
				int sharpnum = 1;
				while (line[sharpnum] == '#')
					sharpnum++;
				int spacenum = 1;
				while (line[spacenum + sharpnum] == ' ')
					spacenum++;
				string headname = line.substr(sharpnum + spacenum);
				ss << "<h" << sharpnum << ">" << headname << "</h" << sharpnum << ">" << endl;
				flag = 0;
			}
			else if (line[0] == '*')
			{
				if (flag != 2)
					ss << "<ul>" << endl;
				int spacenum = 1;
				while (line[spacenum + 1] == ' ')
					spacenum++;
				string formname = line.substr(spacenum + 1);
				ss << "<li>" << formname << "</li>" << endl;
				flag = 2;
			}
			else
			{
				if (flag == 3)
					ss << endl;
				else
					ss << "<p>";
				//
				ss << line;
				flag = 3;
			}
		}
	}
	if (flag == 3)
		ss << "</p>";
	else if (flag == 2)
		ss << "</ul>";
	cout << ss.str() << endl;
	return 0;
}
