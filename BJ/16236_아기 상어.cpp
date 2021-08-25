#include <iostream>
#include <queue>
using namespace std;
/*
* �ʱ� �Ʊ��� ũ��� 2, �����¿� ��ĭ�� ������ �� ����
* ���ʺ���, ���ʺ��� ����
* �ڽź��� ũ�Ⱑ ������ �԰�, ������ �����ļ� ������ �� ����
* �������� �����ϴ� map �� **arr ���� ����� ��
* 
* -1-
* queue �� ���� �� x, y ��ǥ�� ����ִµ� �ڱ⺸�� ���� ��⸦ ������ queue ���� ������ ����ŭ cnt �ø���
* queue �� �����ٸ� cnt ���
* 
* -2-
* 1��ó�� ������ ������ ���� �ݷʰ� ����
* 
* 3
* 0 3 1
* 0 9 0
* 1 0 0
* 
* �϶� (0,2) �� �湮�ؾ� �ϴµ� (2,0) �� �湮
* �� �� �� �ִ� ��� arr���� Ž���ؼ� rec[][] �� üũ�� ��, ���� ���� cnt �� ��ȯ�ؾ� �ҵ�
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
				// queue �� ����ִ� ��� �������� �����鼭 Ȯ��
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
			}	// queue ��

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
	}		// �Է¿Ϸ�

	bfs();

	cout << res;
}