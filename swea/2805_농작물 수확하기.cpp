#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int T, num;
	char tmp;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		cin >> num;
		int** arr = new int* [num];
		for (int i = 0; i < num; i++)
			arr[i] = new int[num];

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				cin >> tmp;
				arr[i][j] = tmp - 48;
			}
		}
		int sum = 0;
		for (int i = 0; i < num; i++) {
			for (int j = abs(num / 2 - i); j < num - abs(num / 2 - i); j++) {
				sum += arr[i][j];
			}
		}
		cout <<"#" << TC << " "  << sum<< "\n";



	}
}