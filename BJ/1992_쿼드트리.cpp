#include <iostream>
using namespace std;
/*
* 안으로 들어갈 때 마다 괄호가 들어가야 함
* (현재 크기의) 전체를 보고 없다면 괄호를 치고 4개중 첫번째로 들어간다
* 두번째로 들어간다
* 세번째 - 이런식으로
*/
int N;
char arr[65][65];

void find(int n, int x, int y) {
	if (n == 1) {
		cout << arr[x][y];
		return;
	}
	char tmp = arr[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (tmp != arr[i][j]) {
				cout << "(";
				find(n >> 1, x, y);
				find(n >> 1, x, y + (n >> 1));
				find(n >> 1, x + (n >> 1), y);
				find(n >> 1, x + (n >> 1), y + (n >> 1));
				cout << ")";
				return;
			}
		}
	}
	cout << tmp;
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	find(N, 0, 0);
}