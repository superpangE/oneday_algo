#include <iostream>
using namespace std;
int arr[101][101];
int N, x, y, res;
int main()
{
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int T = 0; T < N; T++) {
		res = 0;
		cin >> x >> y;
		for (int i = x; i < x + 10; i++)
			for (int j = y; j < y + 10; j++)
				arr[i][j] = 1;
	}
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (arr[i][j] == 1)
				res++;
	cout << res;
}