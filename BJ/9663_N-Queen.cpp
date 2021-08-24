#include <iostream>
using namespace std;
int* arr, N, res = 0;
bool isValid(int x, int y) {
	int idx = x;
	int val = y;
	while (idx-- > 0) 
		if (arr[idx] == y || arr[idx] == --val) return (false);
	idx = x;
	val = y;
	while (idx-- > 0)
		if (arr[idx] == y || arr[idx] == ++val) return (false);
	return (true);
}
void find(int idx) {
	if (idx >= N) {
		res++;
		return;
	}

	for (int i = 0; i < N; i++) {
		arr[idx] = i;
		if (!isValid(idx, arr[idx])) continue;
		find(idx + 1);
	}
}
void init(int n) {
	for (int i = 0; i < n; i++)
		arr[i] = -1;
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	arr = new int[N];	// 입력완료
	init(N);
	find(0);
	cout << res;
}