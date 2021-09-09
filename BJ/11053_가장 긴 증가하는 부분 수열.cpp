#include <iostream>
using namespace std;
/*
* 최대길이가 1000 이고, 시간제한이 1초
* 수열 인덱스가 저장되어있는 arr를 전체를 돌면서,
* arr 보다 작은 인덱스들을 모두 확인
* O(N^2) 의 시간복잡도가 나올 예정
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