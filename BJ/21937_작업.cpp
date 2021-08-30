#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
* 방향 간선그래프를 거꾸로 입력받음
* Queue 는 현재값 x 랑 몇번째인지 확인하는 cnt 두개로 만듬
* Queue에 넣어서 bfs 로 확인
* 
* + 몇초동안 작업을 해야하냐가 아니라 작업을 몇개 해야하는지에 대한 문제라서 cnt 가 필요없어서 구조체 삭제
*/
int N, M, X, res;
vector<vector<int>>v;
bool isVisited[100001];
queue<int>q;
void bfs() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if (isVisited[v[x][i]]) continue;
			isVisited[v[x][i]] = true;
			q.push(v[x][i]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		vector<int>tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		v[y].push_back(x);
	}
	cin >> X;
	q.push(X);
	isVisited[X] = true;
	bfs();
	for (int i = 0; i <= N; i++) {
		if (isVisited[i]) res++;
	}
	cout << res - 1;
}