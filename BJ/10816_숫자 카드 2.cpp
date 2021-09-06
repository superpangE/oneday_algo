#include <iostream>
#include <vector>
using namespace std;
int N, M;
int arr[20000001];
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp < 0) tmp += 20000000;
		arr[tmp]++;
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp < 0) tmp += 20000000;
		cout << arr[tmp] << " ";
	}
}