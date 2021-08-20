#include <iostream>
using namespace std;
/*
* 델타를 사용해서 4방의 기준을 정할 것
* 1번부터 5번까지 CCTV의 종류에 따라 주는 델타의 갯수가 달라질건데,
* 예를들어 2번 CCTV는 0 과 2를 줄 것.
* 델타 크기인 4만큼 돌면서 해당 CCTV에서의 최소 사각지대를 구한다
* 순열을 사용해서 ?
* 
* 2탄 생각해봤는데
* 감시카메라의 갯수만큼 중복순열을 돌도록 만들어서
* 해당 중복순열이 감시카메라 수에 맞춰 만들어졌을때의 배열을 가지고
* 전체 배열을 돌며 사각지대 없애기
* CCTV의 종류에 따라서 다른 인덱스도 도는것 판단해보기
*   -> 2번과 5번 CCTV는 네번까지 안돌아도 상관없는데 이건 생각좀 해봐야할듯
* 
*/

// 구조체로 카메라 위치를 받아서 배열로 저장
struct loc {
	int x;
	int y;
	int ver;
};

int N, M, arr[8][8], cam, shot[8], minv;
int dx[] = { -1, 0, 1, 0 ,-1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 ,0, -1, 0, 1 };
loc camloc[8];

bool isValid(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < M);
}

void chk(int sarr[]) {
	int tmparr[8][8];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmparr[i][j] = arr[i][j];

	for (int i = 0; i < cam; i++) {
		// 카메라에 따라 나누기
		int ver = camloc[i].ver;
		//카메라가 1번
		if (ver == 1) {
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i]]);
				int my = camloc[i].y + (j * dy[sarr[i]]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
		}
		//카메라가 2번
		if (ver == 2) {
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i]]);
				int my = camloc[i].y + (j * dy[sarr[i]]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 2]);
				int my = camloc[i].y + (j * dy[sarr[i] + 2]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
		}
		//카메라가 3번
		if (ver == 3) {
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i]]);
				int my = camloc[i].y + (j * dy[sarr[i]]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 1]);
				int my = camloc[i].y + (j * dy[sarr[i] + 1]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}

		}
		//카메라가 4번
		if (ver == 4) {
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i]]);
				int my = camloc[i].y + (j * dy[sarr[i]]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 1]);
				int my = camloc[i].y + (j * dy[sarr[i] + 1]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 2]);
				int my = camloc[i].y + (j * dy[sarr[i] + 2]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
		}
		//카메라가 5번
		if (ver == 5) {
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i]]);
				int my = camloc[i].y + (j * dy[sarr[i]]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 1]);
				int my = camloc[i].y + (j * dy[sarr[i] + 1]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 2]);
				int my = camloc[i].y + (j * dy[sarr[i] + 2]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
			for (int j = 1; j < 8; j++) {
				int mx = camloc[i].x + (j * dx[sarr[i] + 3]);
				int my = camloc[i].y + (j * dy[sarr[i] + 3]);
				if (!isValid(mx, my) || tmparr[mx][my] == 6)
					break;
				if (tmparr[mx][my] == 0)
					tmparr[mx][my] = -1;
			}
		}
	}


	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmparr[i][j] == 0)
				cnt++;
		}
	}

	if (cnt < minv)
		minv = cnt;
}

void perm(int lim, int depth) {
	if (depth == lim) {
		// 중복순열 완성, shot 배열에 담겨있음

		chk(shot);
		return;
	}

	for (int i = 0; i < 4; i++) {
		shot[depth] = i;
		perm(lim, depth + 1);
	}

}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	int k = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (!(arr[i][j] == 0 || arr[i][j] == 6)) {
				cam++;
				camloc[k].x = i;
				camloc[k].y = j;
				camloc[k].ver = arr[i][j];
				k++;
			}
		}			// 입력 완료
	minv = 2147483647;

	
	// 카메라 0 부터 3만큼 순열 중복되게 만드는 함수로
	perm(cam, 0);
	cout << minv;
}