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

int N, M, arr[8][8], cam, shot[8], minv;
int dx[] = { -1, 0, 1, 0 ,-1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 ,0, -1, 0, 1 };
loc camloc[8];

bool isValid(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < M);
}

void chk(int sarr[]) {
	int tmparr[8][8];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmparr[i][j] = arr[i][j];

	for (int i = 0; i < cam; i++) {
		// ī�޶� ���� ������
		int ver = camloc[i].ver;
		//ī�޶� 1��
		if (ver == 1) {
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i]]);
				int my = camloc[i].y + (j * dy[sarr[i]]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
		}
		//ī�޶� 2��
		if (ver == 2) {
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i]]);
				int my = camloc[i].y + (j * dy[sarr[i]]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 2]);
				int my = camloc[i].y + (j * dy[sarr[i] + 2]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
		}
		//ī�޶� 3��
		if (ver == 3) {
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i]]);
				int my = camloc[i].y + (j * dy[sarr[i]]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 1]);
				int my = camloc[i].y + (j * dy[sarr[i] + 1]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}

		}
		//ī�޶� 4��
		if (ver == 4) {
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i]]);
				int my = camloc[i].y + (j * dy[sarr[i]]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 1]);
				int my = camloc[i].y + (j * dy[sarr[i] + 1]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 2]);
				int my = camloc[i].y + (j * dy[sarr[i] + 2]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
		}
		//ī�޶� 5��
		if (ver == 5) {
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i]]);
				int my = camloc[i].y + (j * dy[sarr[i]]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 1]);
				int my = camloc[i].y + (j * dy[sarr[i] + 1]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 2]);
				int my = camloc[i].y + (j * dy[sarr[i] + 2]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 3]);
				int my = camloc[i].y + (j * dy[sarr[i] + 3]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
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