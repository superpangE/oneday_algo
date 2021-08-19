#include <iostream>
using namespace std;
/*
* 알파벳 대문자만 있으니깐 체크할 배열 26개짜리 하나 만듬
* 탐색을 다한걸 어떻게 판단할지.
*	-> 델타로 다 확인했을 때 없을 때 마다 chk 배열 확인해서 maxv 와 비교
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
	}			// 입력 끝
	maxv = -2147483647;
	find(0, 0);
	cout << maxv;
}