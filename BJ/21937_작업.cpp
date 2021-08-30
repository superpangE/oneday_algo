#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
* ���� �����׷����� �Ųٷ� �Է¹���
* Queue �� ���簪 x �� ���°���� Ȯ���ϴ� cnt �ΰ��� ����
* Queue�� �־ bfs �� Ȯ��
* 
* + ���ʵ��� �۾��� �ؾ��ϳİ� �ƴ϶� �۾��� � �ؾ��ϴ����� ���� ������ cnt �� �ʿ��� ����ü ����
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