#include <iostream>
#include <queue>
using namespace std;
/*
* queue 사방을 확인하여 사방에 0이 있는 것들만 큐에 삽입
* bfs로 하면 될것 같은데
* 마지막이란걸 어떻게 알까
* 
* 처음 큐에 넣는걸 잘못했음.
* 중앙이 뻥 뚫린 치즈같은 경우를 어떻게 잡아야할지.
* 맨 처음은 전체를 다보는식으로하고,
* 두번째부터는 bfs로 찾기 ?
* 
* 1. (0,0) 에서 도달할 수 있는 모든 1을 queue 에 집어넣기
* 2. 큐에 들어가있는 값들을 arr상에서도 0으로 바꿔준다
* 3. 1번 반복
*/
queue <pair<int,int>>q;
queue<pair<int, int>>tmpq;
int N, M, arr[101][101], t_time;
bool isVisited[101][101];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
bool isValid(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < M);
}
void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
}
void add_queue() {
	t_time++;
	tmpq.push(make_pair(0, 0));
	while (!tmpq.empty()) {
		int x = tmpq.front().first;
		int y = tmpq.front().second;
		tmpq.pop();
		for (int i = 0; i < 4; i++) {
			int mx = x + dx[i];
			int my = y + dy[i];
			if (isValid(mx, my) && !isVisited[mx][my]) {
				isVisited[mx][my] = true;
				if (arr[mx][my] == 0)
					tmpq.push(make_pair(mx, my));
				else {
					q.push(make_pair(mx, my));
				}
			}

		}
	}
}
void search() {
	int  cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		arr[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int mx = x + dx[i];
			int my = y + dy[i];
			if (isValid(mx, my) && !isVisited[mx][my] && arr[mx][my] == 1) {
				isVisited[mx][my] = true;
			}
		}

	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			isVisited[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				add_queue();
				search();
				return;
			}
		}
	}
	cout << t_time << "\n" << cnt;
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	init();
	add_queue();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			isVisited[i][j] = false;
	search();
}