#include <iostream>
#include <queue>
using namespace std;
int main() {
	for (int TC = 1; TC <= 10; TC++) {
		int num, tmp;
		queue<int>q;
		cin >> num;
		for (int i = 0; i < 8; i++) {
			cin >> num;
			q.push(num);
		}

		int b = 0;
		while (1) {
			if (++b > 5)
				b = 1;
			tmp = q.front() - b;
			q.pop();
			if (tmp <= 0) {
				q.push(0);
				break;
			}
			q.push(tmp);
		}
		cout << "#" << TC << " ";
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << "\n";
	}
}