#include <iostream>
using namespace std;
/*
* 회사, 집, 고객수인 N 만큼이 좌표로 들어오게 됨
* 구조체를 하나 만들어서 배열안에 x, y 좌표를 집어넣음
* 처음 시작과 마지막 도착은 고정
* 중간에 들리게 되는 N명을 중복없는 순열로 나누어서 그때마다 총 거리를 계산
* 계산한 값중 가장 작은 값을 고른다
*/
struct custom {
	int x;
	int y;
};
int T, N, x, y, hx, hy, cx, cy, *tmparr, minv;		// hx, hy : 집 좌표   cx, cy : 회사 좌표
bool *check;
custom *arr;

void calc() {
	int tmpsave = 0;
	tmpsave += (abs(cx - arr[tmparr[0]].x) + abs(cy - arr[tmparr[0]].y));		// 집에서 첫번째 좌표
	tmpsave += (abs(hx - arr[tmparr[N-1]].x) + abs(hy - arr[tmparr[N-1]].y));		// 마지막 고객 - 집

	for (int i = 0; i < N - 1; i++) {
		tmpsave += abs(arr[tmparr[i]].x - arr[tmparr[i + 1]].x)
			+ abs(arr[tmparr[i]].y - arr[tmparr[i + 1]].y);
	}
	if (minv > tmpsave)
		minv = tmpsave;
}

void perm(int depth) {
	if (depth == N) {
		// tmparr 에 만들어진 순열의 순서에 따라 확인하는 함수로
		calc();
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			tmparr[depth] = i;
			perm(depth + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		minv = 2147483647;
		cin >> N;
		arr = new custom[N + 2];
		check = new bool[N];
		tmparr = new int[N];
		for (int i = 0; i < N; i++)
			check[i] = false;
		cin >> hx >> hy >> cx >> cy;
		for (int i = 0; i < N; i++) 
			cin >> arr[i].x >> arr[i].y;		// 입력 끝

		// 가지고 있는 N 개 만큼 순열 만들기
		perm(0);
		cout << "#" << TC << " " << minv << "\n";
	}
}