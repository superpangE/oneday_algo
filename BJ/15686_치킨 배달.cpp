#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, arr[51][51], res, minv = 2147483647;
vector<pair<int, int>>v;
queue<pair<pair<int, int>, int>>q;
bool result[14], isvisited[51][51];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool isValid(int x, int y) {	// 유효한 배열인지
	return ((x >= 0) && (x < N) && (y >= 0) && (y < N));
}

void bfs() {		// 넓이우선탐색
	while (!q.empty()) {
		int a = q.front().first.first, b = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mx = a + dx[i];
			int my = b + dy[i];
			if (!isValid(mx,my)) continue;		// 유효한 배열인지 확인
			if (isvisited[mx][my]) continue;	// 방문했는지 확인
			if (arr[mx][my] == 1)
				res += cnt;

			isvisited[mx][my] = true;
			q.push(make_pair(make_pair(mx, my), cnt + 1));	// 다음큐로 삽입
		}

	}
}

void comb(int target, int cnt, int size) {	// 조합으로 치킨집 뽑기
	if (cnt == M) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				isvisited[i][j] = false;
		res = 0;
		for (int i = 0; i < size; i++) {
			if (result[i]) 
				q.push(make_pair(make_pair(v[i].first, v[i].second), 1));
		}
		bfs();
		if (minv > res)
			minv = res;
	}

	if (target == size)
		return;
	result[target] = true;
	comb(target + 1, cnt + 1, size);
	result[target] = false;
	comb(target + 1, cnt, size);

}

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				v.push_back(make_pair(i, j));
		}
	comb(0, 0, v.size());
	cout << minv;
}