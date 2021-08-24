#include <iostream>
using namespace std;
/*
* 어느 부모를 가르키고 있는지를 알수있는 P[] 를 선언
* 처음 init 으로 N 만큼 P[] 를 초기화
* 0이 들어온다면 a, b 를 union 해줌
* 1이 들어온다면 a, b 를 find 해줌
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
	init();			//P[] 초기화
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