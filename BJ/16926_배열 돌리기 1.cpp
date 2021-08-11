#include <iostream>
using namespace std;

int N, M, R, tmp, tmp2, rmove, cnt;
int main()
{
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> R;
	int** arr = new int*[N];
	if (N > M)
		cnt = M / 2;
	else
		cnt = N / 2;
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}
	int i = 0, j = 0;
	for (int T = 0; T < cnt; T++){
		for (int rt = 0; rt < R; rt++) {
			// 좌측
			tmp = arr[N - i - 1][j];
			for (int x = N - i - 2; x >= i; x--) {
				arr[x + 1][j] = arr[x][j];
			}
			// 상단
			for (int y = j + 1; y < M - j; y++) {
				arr[i][y - 1] = arr[i][y];
			}
			// 우측
			for (int x = i + 1; x < N - i; x++) {
				arr[x - 1][M - j - 1] = arr[x][M - j - 1];
			}
			// 하단
			for (int y = M - j - 2; y >= j; y--) {
				arr[N - i - 1][y + 1] = arr[N - i - 1][y];
			}
			// 하단 움직이기 전 맨 처음 tmp 를 넣어줌
			arr[N - i - 1][j + 1] = tmp;
		}
		i++;
		j++;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}