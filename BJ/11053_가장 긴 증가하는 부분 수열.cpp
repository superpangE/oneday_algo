#include <iostream>
using namespace std;
/*
* �ִ���̰� 1000 �̰�, �ð������� 1��
* ���� �ε����� ����Ǿ��ִ� arr�� ��ü�� ���鼭,
* arr ���� ���� �ε������� ��� Ȯ��
* O(N^2) �� �ð����⵵�� ���� ����
*/
int N, * arr, dp[1001];
void init() {
	cin >> N;
	arr = new int[N];
	int tmp, cnt = 0;
	while (cin >> tmp)
		arr[cnt++] = tmp;
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	init();
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		int maxv = 1;
		for (int j = i; j >= 0; j--) {
			if (arr[i] > arr[j])
				if (maxv <= dp[j])
					maxv = dp[j] + 1;
		}
		dp[i] = maxv;
	}
	int maxv = 0;
	for (int i = 0; i < N; i++)
		if (maxv < dp[i])
			maxv = dp[i];
	cout << maxv;
}