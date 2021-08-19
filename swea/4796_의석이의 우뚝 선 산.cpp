#include <iostream>
using namespace std;
/*
* TC �� �ް� ���� TC ��ŭ arr�� ����
* arr�� 0��° �ε������� ã���鼭, �����ٸ� ��� ���ϱ����� ���� ����
* �������ٸ� �������ٰ� (idx + 1) �� Ŀ�� �� ���� ���� ����
* �ö󰣴ٰ� �Ѵٸ� �ش� �ε����� ��� ������ ��, ���� �ΰ��� ������
* ���� �ε�����
*/
int T, N, *arr, tmp, ucnt, dcnt, res;
bool flag;

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		ucnt = dcnt = res = 0;
		flag = false;
		cin >> N;
		arr = new int[N];
		for (int i = 0; i < N; i++)
			cin >> arr[i];		// �Է� �Ϸ�

		for (int i = 0; i < N - 1; i++) {
			tmp = arr[i];
			if (!flag && arr[i] < arr[i + 1]) {
				ucnt++;
			}
			else if (flag && arr[i] > arr[i + 1]) {
				dcnt++;
			}
			else if (flag && arr[i] < arr[i + 1]) {
				flag = false;
				res += (ucnt * dcnt);
				ucnt = 1;
				dcnt = 0;
			}
			else if (!flag && arr[i] > arr[i + 1]) {
				flag = true;
				dcnt++;
			}
			else if (!flag && arr[i] < arr[i + 1]) {
				flag = false;
			}
		}
		if (flag) res += (ucnt * dcnt);
		cout << "#" << TC << " " <<  res << "\n";
	}
}