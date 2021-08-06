#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	int T, num, div;
	cin >> T;
	string* arr;
	string tmp;
	for (int TC = 1; TC <= T; TC++) {
		int idx = 0;
		cin >> num;
		if (num % 2 == 0)
			div = num / 2;
		else div = (num / 2) + 1;
		arr = new string[num];
		for (int i = 0; i < num; i++) {
			cin >> arr[i];
		}
		cout << "#" << TC << " ";
		for (int i = 0; i< num ; i++) {
			cout << arr[idx] + " ";
			if (i % 2 == 0)
				idx += div;
			else idx -= (div - 1);
		}
		cout << "\n";
	}
}