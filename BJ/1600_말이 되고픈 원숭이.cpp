#include <iostream>
#include <queue>
using namespace std;
/*
* �����¿� 4�� + ��ó���ٴ°� 8���� queue�� ����־ bfs��
* �ð��ʰ� �� �� ������ �׻� �湮üũ + üũ�� Validüũ
* 
* �����߸�����
* �� ������ �� �ִ� Ƚ���� K���� �ƴ϶�, ��ó�� �� �� �ִ� Ƚ���� K��
* ����ü�� skill�̶�� ��ó�� �� Ƚ���� �����ϴ� int�� ���� �߰���
* dx, dy�� 4������ ���°� 4��, ��ó�� �ٴ°� 8���� �ִµ� ��ų�� ������ skill �ϳ��� ����
* ���� ��ġ�� ������ ���� ��� ��ó�� �پ������� ���� isVisited�� �޶����� ������
* isVisited�� 3���� �迭�� �������
*/
struct pos {
	int x;
	int y;
	int cnt;
	int skill;
	pos(int x, int y, int cnt, int skill) {
		this->x = x;
		this->y = y;
		this->cnt = cnt;
		this->skill = skill;
	}
};
queue<pos>q;
bool isVisited[201][201][31];
int arr[201][201];
int K, W, H;
int dx[] = { -1, 1, 0, 0, -1, -1, -2, -2, 1, 1, 2, 2};
int dy[] = { 0, 0, 1, -1, 2, -2, 1, -1, 2, -2, 1, -1 };
bool isValid(int x, int y) {
	return (x >= 0 && y >= 0 && x < H && y < W);
}
void init() {
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> arr[i][j];
}
void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int sk = q.front().skill;
		q.pop();
		if (x == H - 1 && y == W - 1) {
			cout << cnt;
			return;
		}
		for (int i = 0; i < 12; i++) {
			if (i > 3 && sk >= K) break;
			int mx = x + dx[i];
			int my = y + dy[i];
			if (isValid(mx, my) && arr[mx][my] == 0) {
				if (mx == H - 1 && my == W - 1) {
					cout << cnt + 1;
					return;
				}
				if (i > 3) {
					if (!isVisited[mx][my][sk + 1]) {
						q.push(pos(mx, my, cnt + 1, sk + 1));
						isVisited[mx][my][sk + 1] = true;
					}
				}
				else {
					if (!isVisited[mx][my][sk]) {
						q.push(pos(mx, my, cnt + 1, sk));
						isVisited[mx][my][sk] = true;
					}
				}
			}

		}
	}
	cout << "-1";
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	init();
	q.push(pos(0, 0, 0, 0));
	isVisited[0][0][0] = true;
	bfs();
}