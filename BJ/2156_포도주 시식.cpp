#include <iostream>
#include <algorithm>
using namespace std;
int N;
int* arr;
int* dp;
/*
* dp에 현재까지 마실 수 있는 최대의 양을 구하는것
* 몇개를 봐야하는지
* 연속해서 두개까지만 먹을 수 있으니깐 세개?
* 세개를 기준으로 둔다면, 현재를 먹었다.
* 그럼 앞에 두개가 나올 수 있는 경우는 ?
* o x o
* x o o
* dp[n] = arr[n] + dp[n-2];
* or
* dp[n] = arr[n] + arr[n-1] + dp[n-3];
* 
* 두개 중에 더 큰거를 가져오면 됨
*/
void init() {
	cin >> N;
	arr = new int[N];
	dp = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	init();

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[1], arr[1] + arr[2]);
	dp[2] = max(dp[2], arr[0] + arr[2]);
	for (int i = 3; i < N; i++) {
		if ((arr[i] + dp[i - 2]) > (arr[i] + arr[i - 1] + dp[i - 3]))
			dp[i] = arr[i] + dp[i - 2];
		else
			dp[i] = arr[i] + arr[i - 1] + dp[i - 3];
		dp[i] = max(dp[i], dp[i - 1]);
	}
	int maxv = 0;
	for (int i = 0; i < N; i++) {
		if (maxv < dp[i])
			maxv = dp[i];
	}
	cout << maxv;
}