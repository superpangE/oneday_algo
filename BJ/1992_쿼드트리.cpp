#include <iostream>
using namespace std;
/*
* ������ �� �� ���� ��ȣ�� ���� ��
* (���� ũ����) ��ü�� ���� ���ٸ� ��ȣ�� ġ�� 4���� ù��°�� ����
* �ι�°�� ����
* ����° - �̷�������
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