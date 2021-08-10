#include <queue>
#include <iostream>
using namespace std;
queue<int>q;
int main()
{
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	int N, K, tmp;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		q.push(i + 1);
	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < K; i++) {
			tmp = q.front();
			q.pop();
			if (i == K - 1) {
				cout << tmp;
				if (!q.size()) {
					cout << ">";
					continue;
				}
				cout << ", ";
				continue;
			}
			q.push(tmp);
		}
	}
}