#include <iostream>
#include <queue>
using namespace std;
/*
* queue ����� Ȯ���Ͽ� ��濡 0�� �ִ� �͵鸸 ť�� ����
* bfs�� �ϸ� �ɰ� ������
* �������̶��� ��� �˱�
* 
* ó�� ť�� �ִ°� �߸�����.
* �߾��� �� �ո� ġ��� ��츦 ��� ��ƾ�����.
* �� ó���� ��ü�� �ٺ��½������ϰ�,
* �ι�°���ʹ� bfs�� ã�� ?
* 
* 1. (0,0) ���� ������ �� �ִ� ��� 1�� queue �� ����ֱ�
* 2. ť�� ���ִ� ������ arr�󿡼��� 0���� �ٲ��ش�
* 3. 1�� �ݺ�
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