#include <iostream>
using namespace std;
int M, K, arr1[101][101], arr2[101][101], res[101][101], tmp, resx, resy;
void init() {
	cin >> M >> K;
	resx = M;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> arr1[i][j];
	cin >> M >> K;
	resy = K;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> arr2[i][j];
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	init();	// 입력완료

	for (int i = 0; i < resx; i++) {
		for (int j = 0; j < resy; j++) {
			tmp = 0;
			for (int a = 0; a < M; a++) 
				tmp += (arr1[i][a] * arr2[a][j]);
			res[i][j] = tmp;
		}
	}
	for (int i = 0; i < resx; i++) {
		for (int j = 0; j < resy; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}