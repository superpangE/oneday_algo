#include <iostream>
#include <queue>
using namespace std;
/*
* ù��°���� 4���� �� ���ƺ���.
* �ٸ� ���� �����Ѵٸ� 4������
* �� ���ٸ� ù��° ���� ���� ���/�Ķ��� ����
*/
struct pos {
	int x;
	int y;
	int s;
	pos(int ix, int iy, int is) {
		x = ix;
		y = iy;
		s = is;
	}
};
int N, W, B;
int arr[129][129];
queue<pos>q;
void calc() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int s = q.front().s;
		q.pop();
		int tmp = arr[x][y];
		bool flag = false;
		for (int i = x; i < x + s; i++) {
			for (int j = y; j < y + s; j++) {
				if (tmp != arr[i][j]) {
					q.push(pos(x, y, s >> 1));
					q.push(pos(x + (s >> 1), y, s >> 1));
					q.push(pos(x, y + (s >> 1), s >> 1));
					q.push(pos(x + (s >> 1), y + (s >> 1), s >> 1));
					i = x + s; j = y + s;
					flag = true;
				}
			}
		}
		if (!flag) {
			if (tmp == 1) B++;
			else W++;
		}
	}
}
void init() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	init();	// �Է¿Ϸ�

	q.push(pos(0, 0, N));
	calc();
	cout << W << "\n" << B;
}