#include <iostream>
#include <queue>
using namespace std;
struct box {
	int x;
	int sec;
	box(int xx, int yy) {
		x = xx;
		sec = yy;
	}
};
int N, K, cnt, ttime = -1;
bool isVisited[101001];
bool flag = false;
queue<box>q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int sec = q.front().sec;
		q.pop();
		isVisited[x] = true;
		if (x == K) {
			flag = true;
			if (ttime < 0) {
				ttime = sec;
				cnt++;
			}
			else {
				if (ttime == sec) cnt++;
			}
			continue;
		}
		if (!flag) {
			if (x + 1 <= K && !isVisited[x + 1]) 
				q.push(box(x + 1, sec + 1));
			if (x - 1 >= 0 && !isVisited[x - 1])
				q.push(box(x - 1, sec + 1));
			if (2 * x < 101000 && !isVisited[2 * x])
				q.push(box(2 * x, sec + 1));
		}
	}
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	q.push(box(N, 0));
	bfs();
	cout << ttime << "\n" << cnt;
}