#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[1001][3], res[1001][3];
void init() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
}
int main() {	// 0-R 1-G 2-B
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	init();
	res[0][0] = arr[0][0], res[0][1] = arr[0][1], res[0][2] = arr[0][2];
	
	for (int i = 1; i < N; i++) {
		res[i][0] = min(res[i - 1][1], res[i - 1][2]) + arr[i][0];
		res[i][1] = min(res[i - 1][0], res[i - 1][2]) + arr[i][1];
		res[i][2] = min(res[i - 1][0], res[i - 1][1]) + arr[i][2];
	}
	cout << min(res[N - 1][0], min(res[N - 1][1], res[N - 1][2]));
}