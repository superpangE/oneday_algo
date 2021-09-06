#include <iostream>
using namespace std;
/*
* 거리를 읽고 최소 연료값으로 곱해서 sum 에 더하기
*/
typedef unsigned long long ll;
int N, arr1[100001], arr2[100001];
ll sum = 0, minv = 2147483647;
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++)
		cin >> arr1[i];
	for (int i = 0; i < N; i++)
		cin >> arr2[i];
	for (int i = 0; i < N - 1; i++) {
		if (minv > arr2[i]) minv = arr2[i];
		sum += (minv * arr1[i]);
	}
	cout << sum;
}