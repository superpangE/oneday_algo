#include <iostream>
#include <algorithm>
using namespace std;
int karr[9],iarr[9], res[9];
bool flag, isvisited[9];
int win, lose, me, you;

void dfs(int idx) {
	if (idx == 9) {
		me = 0; you = 0;
		for (int i = 0; i < 9; i++) {
			if (karr[i] > res[i])
				me += (karr[i] + res[i]);
			else if (karr[i] < res[i])
				you += (karr[i] + res[i]);
		}
		if (me > you)
			win++;
		else if (you > me)
			lose++;
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (isvisited[i]) continue;

		isvisited[i] = true;
		res[idx] = iarr[i];
		dfs(idx + 1);
		isvisited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		for (int i = 0; i < 9; i++)
			cin >> karr[i];
		int idx = 0;
		for (int i = 1; i <= 18; i++) {
			flag = false;
			for (int j = 0; j < 9; j++) {
				if (karr[j] == i)
					flag = true;
			}
			if (!flag)
				iarr[idx++] = i;
		} // 여기까지 karr 와 iarr 에 각각 값을 집어 넣음 flag 사용 끝
		win = 0; lose = 0;
		dfs(0);

		cout << "#" << TC << " " << win << " " << lose << "\n";

	}
}