#include <iostream>
#include <queue>
using namespace std;
/*
* 초기 아기상어 크기는 2, 상하좌우 한칸씩 움직일 수 있음
* 위쪽부터, 왼쪽부터 먹음
* 자신보다 크기가 작으면 먹고, 같으면 지나쳐서 움직일 수 있음
* 물고기들이 존재하는 map 인 **arr 따로 만들어 줌
* 
* -1-
* queue 에 내가 갈 x, y 좌표를 집어넣는데 자기보다 작은 고기를 만나면 queue 비우고 움직인 수만큼 cnt 올리기
* queue 가 끝난다면 cnt 출력
* 
* -2-
* 1번처럼 했을때 다음과 같은 반례가 있음
* 
* 3
* 0 3 1
* 0 9 0
* 1 0 0
* 
* 일때 (0,2) 를 방문해야 하는데 (2,0) 을 방문
* 상어가 갈 수 있는 모든 arr들을 탐색해서 rec[][] 에 체크한 뒤, 가장 작은 cnt 를 반환해야 할듯
*/
int N, arr[21][21], res, s_size, eat, point;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
bool isVisited[21][21];
int rec[21][21];
queue<pair<pair<int, int>, int>>q;

bool isValid(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < N);
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		isVisited[x][y] = true;
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			int mx = x + dx[i];
			int my = y + dy[i];

			if (!isValid(mx, my) || isVisited[mx][my] || arr[mx][my] > s_size) continue;
			if (arr[mx][my] == s_size || arr[mx][my] == 0) {
				isVisited[mx][my] = true;
				q.push(make_pair(make_pair(mx, my), cnt+1));
			}
			else if (arr[mx][my] < s_size) {
				rec[mx][my] = cnt;
				flag = true;
				// queue 에 담겨있는 모든 정보들을 꺼내면서 확인
			}

		}
		if (flag) {
			while (!q.empty()) {
				int tx = q.front().first.first;
				int ty = q.front().first.second;
				int tcnt = q.front().second;
				q.pop();

				for (int w = 0; w < 4; w++) {
					int tmx = tx + dx[w];
					int tmy = ty + dy[w];

					if (!isValid(tmx, tmy) || isVisited[tmx][tmy] || arr[tmx][tmy] > s_size) continue;
					isVisited[tmx][tmy] = true;
					if (arr[tmx][tmy] != 0 && arr[tmx][tmy] < s_size) {
						rec[tmx][tmy] = tcnt;
					}
				}
			}	// queue 끝

			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					if (rec[a][b] == cnt) {
						arr[a][b] = 0;
						q.push(make_pair(make_pair(a, b), 1));
						res += cnt;
						a = N; b = N;
					}
				}
			}

			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					rec[a][b] = 0;
					isVisited[a][b] = false;
				}
			}
			eat++;
			if (eat == s_size) {
				s_size++;
				eat = 0;
			}
			bfs();
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	res = 0; s_size = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				q.push(make_pair(make_pair(i, j), 1));
				arr[i][j] = 0;
			}
		}
	}		// 입력완료

	bfs();

	cout << res;
}