#include <iostream>
using namespace std;
/*
* ��� �θ� ����Ű�� �ִ����� �˼��ִ� P[] �� ����
* ó�� init ���� N ��ŭ P[] �� �ʱ�ȭ
* 0�� ���´ٸ� a, b �� union ����
* 1�� ���´ٸ� a, b �� find ����
*/
int N, M, *P;

int ft_find(int x) {
	if (x == P[x]) return (x);
	return (P[x] = ft_find(P[x]));
}
void ft_union(int x, int y) {
	int mx = ft_find(x);
	int my = ft_find(y);

	if (mx == my) return;
	P[mx] = my;
}
void init() {
	for (int i = 0; i < N + 1; i++)
		P[i] = i;
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	P = new int[N + 1];
	init();			//P[] �ʱ�ȭ
	for (int i = 0; i < M; i++) {
		int cnt, a, b;

		cin >> cnt >> a >> b;
		if (!cnt) ft_union(a, b);
		else {
			if (ft_find(a) == ft_find(b))
				cout << "YES\n";
			else cout << "NO\n";
		}
	}

}