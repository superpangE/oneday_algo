#include <iostream>
#include <vector>
using namespace std;
/*
	1. �������� �� N ������ (N/2) ���� ����
	2. N/2 ��ŭ �� ������ �ΰ��� ������ ��� arr[i][j] �� ���� �� ���Ѵ�
	3. ���� ū ���� ����
	4. �ִ��϶��� �� 16���� ��ᰡ ���ö� : (�������� �� 12,000ȸ)
	5. ������ 8���� 2���� ���� Ƚ�� : 56ȸ
	100�� ���϶� ��������
*/

int arr[16][16], T, N, *saveBox1, saveBox2[2], *saveBox3, saveBox4[2], Amax, Bmax, minv;
bool chk[16];
vector<int>v;

void sum(int box[], int sel) {
	if (sel == 1)
		Amax += arr[box[0]][box[1]];
	else
		Bmax += arr[box[0]][box[1]];
}

void perm(int depth, int Boxs[], int inputbox[], int find) {	// ������ �� ������ saveBox2 �� ����Ǿ� ����
	if (depth == 2) {
		sum(inputbox, find);
		return;
	}
	
	for (int i = 0; i < N/2; i++) {
		if (!chk[i]) {
			chk[i] = true;
			inputbox[depth] = Boxs[i];
			perm(depth + 1, Boxs, inputbox, find);
			chk[i] = false;
		}
	}
}

void comb(int depth, int next) {
	if (depth == N / 2) {
		// �� �Լ� -> saveBox �� ����Ǿ� �ִ� ������ ������ Ǭ��. bool chk �ʱ�ȭ �ϱ�
		int k = 0;
		Amax = 0, Bmax = 0;
		for (int i = 0; i < N; i++) {		// saveBox1 �� ���°��� saveBox3 �� �����ϱ�
			bool flag = false;
			for (int j = 0; j < N/2; j++) {
				if (saveBox1[j] == i)
					flag = true;
			}
			if (!flag) saveBox3[k++] = i;
		}
		perm(0, saveBox1, saveBox2, 0);
		perm(0, saveBox3, saveBox4, 1);

		if (abs(Amax - Bmax) < minv)
			minv = abs(Amax - Bmax);
		return;
	}
	for (int i = next; i < N; i++) {
		saveBox1[depth] = i;
		comb(depth + 1, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];	// �Է� �Ϸ�

		// N ���߿� N/2 ��ŭ�� �������� ����
		saveBox1 = new int[N / 2];
		saveBox3 = new int[N / 2];
		minv = 2147483647;
		comb(0, 0);
		cout << "#" << TC << " " << minv << "\n";
	}
}