#include <iostream>
using namespace std;
/*
* (-1, 1), (0, 1), (1, 1) 세가지 방향으로 움직일 수 있음
* 차례로 3방을 확인하면서 다음것을 확인할 수 있도록.
* 확실하게 이어졌다고 한다면 장애물로 표현하고. cnt 하나 올리기
* 백트래킹 사용
*/
int R, C, cnt;
int dx[] = { -1, 0, 1 };
int dy[] = { 1, 1, 1 };
char arr[10001][501];
bool isVisited[10001][501];
int pipe[501];

bool isValid(int x, int y) {
	return (x >= 0 && y >= 0 && x < R && y < C);
}

void find(int x, int y) {

	pipe[y] = x;
	if (y == C - 1) {
		for (int i = 0; i < C; i++)
			arr[pipe[i]][i] = 'x';
		cnt++;
		return;
	}
	isVisited[x][y] = true;
	for (int k = 0; k < 3; k++) {
		int mx = x + dx[k];
		int my = y + dy[k];

		if (isValid(mx, my) && !isVisited[mx][my] && arr[mx][my] == '.') {
			find(mx, my);
			if (arr[mx][my] != '.') return;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];		// 입력 완료
	cnt = 0;

	for (int i = 0; i < R; i++) {
		find(i, 0);
	}
	cout << cnt;
}