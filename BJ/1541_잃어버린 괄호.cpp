#include <iostream>
using namespace std;
int N, sum;
char c;
bool flag = false;
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	sum += N;
	while (cin >> c) {
		if (c == '-')
			flag = true;
		cin >> N;
		if (flag)
			sum -= N;
		else
			sum += N;
	}
	cout << sum;
}