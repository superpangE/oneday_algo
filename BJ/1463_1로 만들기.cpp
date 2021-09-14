#include <iostream>
#include <queue>
using namespace std;
queue <pair<int,int>>q;
int N;
bool* dp;
void init() {
	cin >> N;
	dp = new bool[N + 1];
	for (int i = 0; i < N + 1; i++)
		dp[i] = false;
	q.push(make_pair(N, 0)); dp[N] = true;
}
void search() {
	while (!q.empty()) {
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (n == 1) {
			cout << cnt;
			return;
		}
		if (n % 3 == 0 && !dp[n/3]) {
			dp[n / 3] = true;
			q.push(make_pair(n / 3, cnt + 1));
		}
		if (n % 2 == 0 && !dp[n/2]) {
			dp[n / 2] = true;
			q.push(make_pair(n / 2, cnt + 1));
		}
		if (n > 1 && !dp[n - 1]) {
			dp[n - 1] = true;
			q.push(make_pair(n - 1, cnt + 1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	init();
	search();

}