#include <iostream>
#include <queue>
using namespace std;
priority_queue<int>q;
/*
* p-queue 사용해서 빼고 넣기 반복
*/
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	int N, da, tmp, cnt = 0;;
	cin >> N >> da;
	for (int i = 1; i < N; i++) {
		cin >> tmp;
		q.push(tmp);
	}
	while ( q.top() >= da) {
		tmp = q.top();
		q.pop();
		cnt++;	da++;
		q.push(--tmp);
	}
	cout << cnt;
}