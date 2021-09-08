#include <iostream>
using namespace std;
/*
* -1-
* 투포인터같은거 사용해볼수 있지 않을까
* 앞(F) 뒤(B) 가 있다고 생각
* F 와 B 사이의 합이 양수라면 F 한칸씩 늘리기
* F 와 B 사이의 합이 음수라면 B 한칸씩 늘리기
* 가장큰값 출력
* 
* -2-
* DP로 해보면 어떨까
* DP에 어떤걸 저장할까
* (자신포함)현재까지 왔을때 가장 큰 값들의 합?
* dp[n] = dp[n-1] + arr[n] 을 기본값
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