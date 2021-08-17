#include <iostream>
using namespace std;
int N, r, c;

int find(int N, int r, int c) {
	if (N == 0)	return (1);

	int size = 1 << (N - 1);

	if (r < size) {
		if (c < size)
			return (find(N - 1, r, c));

		return ((size * size) + find(N - 1, r, c - size));
	}
	else {
		if (c < size)
			return ((2 * (size * size)) + find(N - 1, r - size, c));

		return ((3 * (size * size)) + find(N - 1, r - size, c - size));
	}
}

int main() {
	cin >> N >> r >> c;

	cout << find(N, r, c) - 1;

}