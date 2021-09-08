#include <iostream>
using namespace std;
/*
* -1-
* �������Ͱ����� ����غ��� ���� ������
* ��(F) ��(B) �� �ִٰ� ����
* F �� B ������ ���� ������ F ��ĭ�� �ø���
* F �� B ������ ���� ������� B ��ĭ�� �ø���
* ����ū�� ���
* 
* -2-
* DP�� �غ��� ���
* DP�� ��� �����ұ�
* (�ڽ�����)������� ������ ���� ū ������ ��?
* dp[n] = dp[n-1] + arr[n] �� �⺻��
*/
int N, *arr, dp[100001], res = -1001;
void calc(int n) {
	if (n == 0) {
		dp[0] = arr[0];
		return ;
	}
	if (dp[n - 1] < 0) dp[n] = arr[n];
	else dp[n] = dp[n - 1] + arr[n];
}
void init() {
	cin >> N;
	arr = new int[N];
	int cnt = 0;
	int tmp;
	while (cin >> tmp)
		arr[cnt++] = tmp;
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	init();

	for (int i = 0; i < N; i++)
		calc(i);

	for (int i = 0; i < N; i++)
		if (dp[i] > res) res = dp[i];

	cout << res;
}