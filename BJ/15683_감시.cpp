#include <iostream>
using namespace std;
/*
* ��Ÿ�� ����ؼ� 4���� ������ ���� ��
* 1������ 5������ CCTV�� ������ ���� �ִ� ��Ÿ�� ������ �޶����ǵ�,
* ������� 2�� CCTV�� 0 �� 2�� �� ��.
* ��Ÿ ũ���� 4��ŭ ���鼭 �ش� CCTV������ �ּ� �簢���븦 ���Ѵ�
* ������ ����ؼ� ?
*
* 2ź �����غôµ�
* ����ī�޶��� ������ŭ �ߺ������� ������ ����
* �ش� �ߺ������� ����ī�޶� ���� ���� ������������� �迭�� ������
* ��ü �迭�� ���� �簢���� ���ֱ�
* CCTV�� ������ ���� �ٸ� �ε����� ���°� �Ǵ��غ���
*   -> 2���� 5�� CCTV�� �׹����� �ȵ��Ƶ� ������µ� �̰� ������ �غ����ҵ�
*
*/

// ����ü�� ī�޶� ��ġ�� �޾Ƽ� �迭�� ����
struct loc {
	int x;
	int y;
	int ver;
};

int N, M, arr[8][8], tmparr[8][8], cam, shot[8], minv;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
loc camloc[8];

bool isValid(int x, int y) {
	return (x >= 0 && y >= 0 && x < N&& y < M);
}

void paint_arr(int x, int y, int dir) {
	if (dir > 3)
		dir -= 4;
	for (int i = 1; i < 8; i++) {
		int mx = x + (i * dx[dir]);
		int my = y + (i * dy[dir]);
		if (!isValid(mx, my) || tmparr[mx][my] == 6)
			return;
		if (tmparr[mx][my] == 0)
			tmparr[mx][my] = -1;
	}
}

void chk(int sarr[]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmparr[i][j] = arr[i][j];

	for (int i = 0; i < cam; i++) {
		// ī�޶� ���� ������
		int ver = camloc[i].ver;

		if (ver == 1) {
			paint_arr(camloc[i].x, camloc[i].y, sarr[i]);
		}

		if (ver == 2) {
			paint_arr(camloc[i].x, camloc[i].y, sarr[i]);
			paint_arr(camloc[i].x, camloc[i].y, sarr[i] + 2);
		}

		if (ver == 3) {
			paint_arr(camloc[i].x, camloc[i].y, sarr[i]);
			paint_arr(camloc[i].x, camloc[i].y, sarr[i] + 1);
		}

		if (ver == 4) {
			paint_arr(camloc[i].x, camloc[i].y, sarr[i]);
			paint_arr(camloc[i].x, camloc[i].y, sarr[i] + 1);
			paint_arr(camloc[i].x, camloc[i].y, sarr[i] + 2);
		}

		if (ver == 5) {
			paint_arr(camloc[i].x, camloc[i].y, sarr[i]);
			paint_arr(camloc[i].x, camloc[i].y, sarr[i] + 1);
			paint_arr(camloc[i].x, camloc[i].y, sarr[i] + 2);
			paint_arr(camloc[i].x, camloc[i].y, sarr[i] + 3);
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmparr[i][j] == 0)
				cnt++;
		}
	}

	if (cnt < minv)
		minv = cnt;
}

void perm(int lim, int depth) {
	if (depth == lim) {
		// �ߺ����� �ϼ�, shot �迭�� �������

		chk(shot);
		return;
	}

	for (int i = 0; i < 4; i++) {
		shot[depth] = i;
		perm(lim, depth + 1);
	}

}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	int k = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (!(arr[i][j] == 0 || arr[i][j] == 6)) {
				cam++;
				camloc[k].x = i;
				camloc[k].y = j;
				camloc[k].ver = arr[i][j];
				k++;
			}
		}			// �Է� �Ϸ�
	minv = 2147483647;


	// ī�޶� 0 ���� 3��ŭ ���� �ߺ��ǰ� ����� �Լ���
	perm(cam, 0);
	cout << minv;
}