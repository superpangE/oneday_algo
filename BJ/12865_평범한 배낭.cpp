#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
* ���� w�� ��ġ v �� ���� ����ü�� �����
* ����ü�� �ڷ������� ���� �迭�� ����
* �κ��������� ���� w �� ���������� �ִ� v �� ã�´�
* 
* - �ð��ʰ��� - 
* + powerset �Լ����� �Ű����� �ΰ��Ѱܼ� �ٷ� Ȯ���ϴ� ���
* + powerset �Լ����� weight �Ӹ� �ƴ϶� value �� �Ѱܼ� �ѹ��� Ȯ��
* + �Լ��� ���� Ȯ���ϴ°� �ƴ϶� ���� ���� Ȯ���ϴ� ���
* 
* - ��Ʈ��ŷ���� Ǫ�� ������ �ƴ� -
* + dp�� ��ȭ�� ������ �ؾ��ϴ� ����
* + dp[���� ��ġ][���� ����] = (���� ������ �� �ִ� �ִ� ��ġ) �� ����
*/
struct box {
	int w;
	int v;
};
int N, K, res, dp[101][100001];
box *arr;
int powerset(int k, int bw) {
	
	if (dp[k][bw] >= 0) return (dp[k][bw]);
	if (k == N) return (0);
	
	dp[k][bw] = powerset(k + 1, bw);	// ���� �ε��� ���� ������ ���� ��
	if (bw + arr[k].w <= K)				// ���� �ε��� ���� ���� �� ��
		dp[k][bw] = max(dp[k][bw], powerset(k + 1, bw + arr[k].w) + arr[k].v);

	return (dp[k][bw]);		// ���� ��ġ����, ���� ���Ա��� ������� ������ �� �� �ִ� �ִ� ����

}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	arr = new box[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i].w;
		cin >> arr[i].v;
	}		// �Է� �Ϸ�
	memset(dp, -1, sizeof(dp));		// dp �� ��������� -1�� �ʱ�ȭ
	cout << powerset(0, 0);
}