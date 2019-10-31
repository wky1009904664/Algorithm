#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(void)
{
	string input; int i;
	getline(cin, input);
	int diss = '0' - 0;
	int inNumber[9];
	inNumber[0] = input[0] - diss;
	for (int i = 1; i < 4; i++) {
		inNumber[i] = input[i+1] - diss;
	}
	for (int i = 4; i < 9; i++) {
		inNumber[i] = input[i + 2] - diss;
	}
	char mark = input[12];
	int result = 0;
	for (int i = 0; i < 9; i++) {
		result += inNumber[i] * (i+1);
	}
	int re = result % 11;
	if (re == 10)
		re = 'X';
	else
		re += diss;
	if (re == mark) {
		cout << "Right" << endl;
	}
	else {
		input[12] = re;
		cout <<input<< endl;
	}

	return 0;
}