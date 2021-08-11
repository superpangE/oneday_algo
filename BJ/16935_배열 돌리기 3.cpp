#include <iostream>
using namespace std;
int N, M, R, tmp, cal, arr[101][101], tmparr[101][101];
bool flag = false;
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	
	for (int TC = 0; TC < R; TC++)
	{
		flag = false;
		cin >> cal;
		switch (cal) {
		case 1:
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++) {
					tmparr[N - i - 1][j] = arr[i][j];
				}
			break;
		case 2:
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++) {
					tmparr[i][M - j - 1] = arr[i][j];
				}
			break;
		case 3:			// 坷弗率栏肺 90档
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					tmparr[i][j] = arr[N - j - 1][i];
				}
			}
			flag = true;
			break;
		case 4:			// 哭率栏肺 90档
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					tmparr[j][i] = arr[i][M - j - 1];
				}
			}
			flag = true;
			break;
		case 5:
			for (int i = 0; i < N / 2; i++)				// 1备开阑 2备开栏肺
				for (int j = 0; j < M / 2; j++)
					tmparr[i][j + (M / 2)] = arr[i][j];
			for (int i = 0; i < (N / 2); i++)			// 2备开阑 3备开栏肺
				for (int j = (M / 2); j < M; j++)		
					tmparr[i + (N / 2)][j] = arr[i][j];
			for (int i = (N / 2); i < N; i++)			// 3备开阑 4备开栏肺
				for (int j = (M / 2); j < M; j++)
					tmparr[i][j - (M / 2)] = arr[i][j];
			for (int i = (N / 2); i < N; i++)			// 4备开阑 1备开栏肺
				for (int j = 0; j < (M / 2); j++)
					tmparr[i - (N / 2)][j] = arr[i][j];
			break;
		case 6:
			for (int i = 0; i < N / 2; i++)				// 1备开阑 4备开栏肺
				for (int j = 0; j < M / 2; j++)
					tmparr[i + (N / 2)][j] = arr[i][j];
			for (int i = 0; i < (N / 2); i++)			// 2备开阑 1备开栏肺
				for (int j = (M / 2); j < M; j++)
					tmparr[i][j - (M / 2)] = arr[i][j];
			for (int i = (N / 2); i < N; i++)			// 3备开阑 2备开栏肺
				for (int j = (M / 2); j < M; j++)
					tmparr[i - (N / 2)][j] = arr[i][j];
			for (int i = (N / 2); i < N; i++)			// 4备开阑 3备开栏肺
				for (int j = 0; j < (M / 2); j++)
					tmparr[i][j + (M / 2)] = arr[i][j];
			break;
		}

		for (int i = 0; i < 100; i++)		// 檬扁拳
			for (int j = 0; j < 100; j++) {
				arr[i][j] = tmparr[i][j];
				tmparr[i][j] = 0;
			}
		if (flag) {
			tmp = N;
			N = M;
			M = tmp;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}