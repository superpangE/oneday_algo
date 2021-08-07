#include <iostream>
using namespace std;
int arr[501][501];
int dp[501][501];
int res, dpsave;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool isValid(int x, int y, int size) {
	return (x >= 0 && y >= 0 && x < size&& y < size);
}

void move(int x, int y, int size, int cnt) {
	if (dp[x][y]) {
		if (dpsave < cnt + dp[x][y] - 1)
			dpsave = cnt + dp[x][y] - 1;
		return;
	}
	if (dpsave < cnt)
		dpsave = cnt;
	for (int i = 0; i < 4; i++) {
		int mx = x + dx[i];
		int my = y + dy[i];

		if (!isValid(mx, my, size))
			continue;
		if (arr[mx][my] > arr[x][y]) {
			move(mx, my, size, cnt + 1);
		}
	}
	for (int i = 0; i < 4; i++) {
		int mx = x + dx[i];
		int my = y + dy[i];

		if (!isValid(mx, my, size))
			continue;
		if (arr[mx][my] > arr[x][y] && dp[mx][my] >= dp[x][y])
			dp[x][y] = dp[mx][my] + 1;
	}
	if (!dp[x][y])
		dp[x][y] = 1;
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	int N, tmp = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			move(i, j, N, 1);
		}
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] > max) {

				max = dp[i][j];
			}
		}
	}
	cout << max;
}