#include <iostream>
using namespace std;
/*
* ���ĺ� �빮�ڸ� �����ϱ� üũ�� �迭 26��¥�� �ϳ� ����
* Ž���� ���Ѱ� ��� �Ǵ�����.
*	-> ��Ÿ�� �� Ȯ������ �� ���� �� ���� chk �迭 Ȯ���ؼ� maxv �� ��
*/
int R, C, ** arr, maxv;
bool chk[26];
char tmp;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool isValid(int x, int y) {
	return (x >= 0 && y >= 0 && x < R && y < C);
}

void find(int x, int y) {
	chk[arr[x][y]] = true;
	for (int i = 0; i < 4; i++) {
		int mx = x + dx[i];
		int my = y + dy[i];
		if (isValid(mx, my) && !chk[arr[mx][my]])
			find(mx, my);
	}
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (chk[i])
			cnt++;
	}
	if (maxv < cnt)
		maxv = cnt;
	chk[arr[x][y]] = false;
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	arr = new int* [R];
	for (int i = 0; i < R; i++) {
		arr[i] = new int[C];
		for (int j = 0; j < C; j++) {
			cin >> tmp;
			arr[i][j] = tmp - 65;
		}
	}			// �Է� ��
	maxv = -2147483647;
	find(0, 0);
	cout << maxv;
}