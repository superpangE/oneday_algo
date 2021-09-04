#include <iostream>
using namespace std;
/*
* 첫번째부터 4방을 다 돌아본다.
* 다른 색이 존재한다면 4조각냄
* 다 같다면 첫번째 값에 따라 흰색/파랑색 증감
*/
int N, W, B;
int arr[129][129];
void calc(int x, int y, int s) {

	int tmp = arr[x][y];
	bool flag = false;
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			if (tmp != arr[i][j]) {
				calc(x, y, s >> 1);
				calc(x + (s >> 1), y, s >> 1);
				calc(x, y + (s >> 1), s >> 1);
				calc(x + (s >> 1), y + (s >> 1), s >> 1);
				return;
			}
		}
	}		
	if (tmp == 1) B++;
	else W++;
}
void init() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	init();	// 입력완료

	calc(0, 0, N);
	cout << W << "\n" << B;
}