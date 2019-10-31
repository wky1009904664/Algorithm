#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	int n, x;
	cin >> n;
	int* arr = (int*)malloc(10000 * sizeof(n));
	for (int i = 0; i < 10000; i++)
		arr[i] = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		++arr[x];
	}
	int max = 0;
	for (int i = 1; i < 10000; i++) {
		if (arr[i] > arr[max]) {
			max = i;
		}
	}
	printf("%d\n", max);
}