#include <iostream>
using namespace std;
/*
* --- �߸�������  �ϳ��� �ø��鼭 �Ǵ��ϴ°� ---
* �κ����� ���� ������ ���� ���ʿ� �ѹ�, �����ʿ� �ѹ� �÷��� �׶����� Ȯ��
* �ϸ� �ɵ�;
*/
int T, N, * arr, res, *tmparr, lsum, rsum, cnt;
bool check[9];

void calc(int depth) {
	if (depth == N) {
		// ī��Ʈ �ø��� return
		cnt++;
		return;
	}
	lsum += tmparr[depth];
	if (lsum < rsum) {
		lsum -= tmparr[depth];
		return;
	}
	calc(depth + 1);
	lsum -= tmparr[depth];
	rsum += tmparr[depth];
	if (lsum < rsum) {
		rsum -= tmparr[depth];
		return;
	}
	calc(depth + 1);
	rsum -= tmparr[depth];
}

void perm(int depth) {
	if (depth == N) {
		rsum = lsum = 0;
		calc(0);
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			tmparr[depth] = arr[i];
			perm(depth + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		res = 0;
		cin >> N;
		arr = new int[N];
		tmparr = new int[N];
		for (int i = 0; i < N; i++)
			cin >> arr[i];			// �Է� �Ϸ�

		// ���� �迭�� ������ �迭�� �κ��������� ������ �Լ���
		cnt = 0;
		perm(0);
		cout << cnt << "\n";
	}
}