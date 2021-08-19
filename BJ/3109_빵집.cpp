#include <iostream>
using namespace std;
/*
* (-1, 1), (0, 1), (1, 1) ������ �������� ������ �� ����
* ���ʷ� 3���� Ȯ���ϸ鼭 �������� Ȯ���� �� �ֵ���.
* Ȯ���ϰ� �̾����ٰ� �Ѵٸ� ��ֹ��� ǥ���ϰ�. cnt �ϳ� �ø���
* ��Ʈ��ŷ ���
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
			cin >> arr[i][j];		// �Է� �Ϸ�
	cnt = 0;

	for (int i = 0; i < R; i++) {
		find(i, 0);
	}
	cout << cnt;
}