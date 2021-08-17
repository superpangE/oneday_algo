#include <iostream>
using namespace std;
int T, N;
bool flag;
char** arr;
int dx[] = { 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1 };
bool isValid(int x, int y) {
	return (x >= 0 && y >= 0 && x < N&& y < N);
}
int chkLoc(int x, int y, int dir, int cnt) {
	if (cnt == 5) {
		return (1);
	}
	int mx = x + dx[dir];
	int my = y + dy[dir];
	if (!isValid(mx, my)) return(0);

	if (arr[mx][my] == 'o') return (chkLoc(mx, my, dir, cnt + 1));
	return (0);
}
int main() {
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		flag = false;
		cin >> N;
		arr = new char*[N];
		for (int i = 0; i < N; i++)
			arr[i] = new char [N];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];		// 읽기 끝
			}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {	// 전체 돌면서 4방 확인
				for (int k = 0; k < 4; k++) {
					if (arr[i][j] == 'o')
						if (chkLoc(i, j, k, 1) == 1) {
							i = N;
							j = N;
							k = 4;
							flag = true;
						}
				}
			}
		}
		if (flag)
			cout << "#" << TC << " YES\n";
		else
			cout << "#" << TC << " NO\n";
	}
}