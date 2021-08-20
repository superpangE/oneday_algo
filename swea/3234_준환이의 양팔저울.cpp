#include <iostream>
using namespace std;
/*
* --- 잘못생각함  하나씩 올리면서 판단하는것 ---
* 부분집합 말고 순열로 만들어서 왼쪽에 한번, 오른쪽에 한번 올려서 그때마다 확인
* 하면 될듯;
*/
int T, N, * arr, res, *tmparr, lsum, rsum, cnt;
bool check[9];

void calc(int depth) {
	if (depth == N) {
		// 카운트 올리고 return
		cnt++;
		return;
	}
	lsum += tmparr[depth];
	if (lsum < rsum) {
		lsum -= tmparr[depth];
		return;
	}
	calc(depth + 1);
	lsum -= tmparr[depth];
	rsum += tmparr[depth];
	if (lsum < rsum) {
		rsum -= tmparr[depth];
		return;
	}
	calc(depth + 1);
	rsum -= tmparr[depth];
}

void perm(int depth) {
	if (depth == N) {
		rsum = lsum = 0;
		calc(0);
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			tmparr[depth] = arr[i];
			perm(depth + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		res = 0;
		cin >> N;
		arr = new int[N];
		tmparr = new int[N];
		for (int i = 0; i < N; i++)
			cin >> arr[i];			// 입력 완료

		// 왼쪽 배열과 오른쪽 배열을 부분집합으로 나누는 함수로
		cnt = 0;
		perm(0);
		cout << cnt << "\n";
	}
}