#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct box {
	int x;
	vector<int> arr;
	box(int xx, vector<int> xarr) {
		x = xx;
		arr = xarr;
	}
};
int N, K;
bool isVisited[101001];
queue<box>q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		vector<int> v = q.front().arr;
		q.pop();
		if (x == K) {
			cout << v.size() - 1<< "\n";
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << " ";
			return;
		}
		if (x + 1 <= K && !isVisited[x + 1]) {
			vector<int>tmp = v;
			isVisited[x + 1] = true;
			tmp.push_back(x + 1);
			q.push(box(x + 1, tmp));
		}
		if (x - 1 >= 0 && !isVisited[x - 1]) {
			vector<int>tmp = v;
			isVisited[x - 1] = true;
			tmp.push_back(x - 1);
			q.push(box(x - 1, tmp));
		}
		if (2 * x < 101000 && !isVisited[2 * x]) {
			vector<int>tmp = v;
			isVisited[2 * x] = true;
			tmp.push_back(2 * x);
			q.push(box(2 * x, tmp));
		}
	}
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	vector<int>v;
	v.push_back(N);
	isVisited[N] = true;
	q.push(box(N, v));
	if (N < K) bfs();
	else {
		cout << N - K << "\n";
		for (int i = N; i >= K; i--)
			cout << i << " ";
	}
}