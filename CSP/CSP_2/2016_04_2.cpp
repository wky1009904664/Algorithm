#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;
int main(void)
{
	int Box[16][10];
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 10; j++)
			cin >> Box[i][j];
	for (int i = 0; i < 10; i++)
		Box[16][i] = 1;
	int input[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> input[i][j];
	int startLine;
	cin >> startLine;
	startLine--;
	int y[4]; int x[4];
	int count = 0;
	for(int i=0;i<4;i++)
		for (int j = 0; j < 4; j++) {
			if (input[i][j] != 0)
			{
				x[count] = i;
				y[count++] = j;
			}
		}

	int row = 1;
	bool exit = false;
	while (1) {
		for (int i = 0; i < 4; i++) {
			if (Box[x[i] + row][y[i] + startLine] != 0) {
				exit = true;
				break;
			}
		}
		if (exit)
			break;
		row++;
	}
	row--;
	for (int i = 0; i < 4; i++)
		Box[x[i] + row][ y[i] + startLine] = 1;

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++)
			cout << Box[i][j] << " ";
		cout << endl;
	}

	return 0;
}