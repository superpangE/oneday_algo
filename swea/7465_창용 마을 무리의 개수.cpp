#include <iostream>
using namespace std;
int* arr, T, N, M, *chk;

void init() {
	arr = new int[N + 1];
	chk = new int[N + 1];
	for (int i = 0; i <= N; i++) {
		arr[i] = i;
		chk[i] = 0;
	}
}

int find(int x) {
	if (arr[x] == x) return (x);
	return (arr[x] = find(arr[x]));
}

void uni(int x, int y) {
	int xRoot = find(x);
	int yRoot = find(y);
	if (xRoot == yRoot) return;
	arr[xRoot] = yRoot;
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		cin >> N >> M;
		int res = 0;
		init();
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			uni(a, b);
		}
		for (int i = 1; i <= N; i++)
			chk[find(i)]++;
		for (int i = 1; i <= N; i++)
			if (chk[i])
				res++;
		cout << "#" << TC << " " << res << "\n";
	}
}