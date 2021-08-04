#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	int T, n, m, tmp;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		cin >> n >> m;
		int** arr = new int*[n];
		int max = -2147483648;
		for (int i = 0; i < n; i++) {
			arr[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> tmp;
				arr[i][j] = tmp;
			}
		}
		for (int i = 0; i < n - m + 1; i++) {
			for (int j = 0; j < n - m + 1; j++) {
				int res = 0;
				for (int k = i; k < i + m; k++) {
					for (int l = j; l < j + m; l++) {
						res += arr[k][l];
					}
				}
				if (res > max)
					max = res;
			}
		}
		cout << "#" <<TC << " " << max << "\n";
	}
}