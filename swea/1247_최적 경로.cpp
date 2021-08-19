#include <iostream>
using namespace std;
/*
* ȸ��, ��, ������ N ��ŭ�� ��ǥ�� ������ ��
* ����ü�� �ϳ� ���� �迭�ȿ� x, y ��ǥ�� �������
* ó�� ���۰� ������ ������ ����
* �߰��� �鸮�� �Ǵ� N���� �ߺ����� ������ ����� �׶����� �� �Ÿ��� ���
* ����� ���� ���� ���� ���� ����
*/
struct custom {
	int x;
	int y;
};
int T, N, x, y, hx, hy, cx, cy, *tmparr, minv;		// hx, hy : �� ��ǥ   cx, cy : ȸ�� ��ǥ
bool *check;
custom *arr;

void calc() {
	int tmpsave = 0;
	tmpsave += (abs(cx - arr[tmparr[0]].x) + abs(cy - arr[tmparr[0]].y));		// ������ ù��° ��ǥ
	tmpsave += (abs(hx - arr[tmparr[N-1]].x) + abs(hy - arr[tmparr[N-1]].y));		// ������ �� - ��

	for (int i = 0; i < N - 1; i++) {
		tmpsave += abs(arr[tmparr[i]].x - arr[tmparr[i + 1]].x)
			+ abs(arr[tmparr[i]].y - arr[tmparr[i + 1]].y);
	}
	if (minv > tmpsave)
		minv = tmpsave;
}

void perm(int depth) {
	if (depth == N) {
		// tmparr �� ������� ������ ������ ���� Ȯ���ϴ� �Լ���
		calc();
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			tmparr[depth] = i;
			perm(depth + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		minv = 2147483647;
		cin >> N;
		arr = new custom[N + 2];
		check = new bool[N];
		tmparr = new int[N];
		for (int i = 0; i < N; i++)
			check[i] = false;
		cin >> hx >> hy >> cx >> cy;
		for (int i = 0; i < N; i++) 
			cin >> arr[i].x >> arr[i].y;		// �Է� ��

		// ������ �ִ� N �� ��ŭ ���� �����
		perm(0);
		cout << "#" << TC << " " << minv << "\n";
	}
}