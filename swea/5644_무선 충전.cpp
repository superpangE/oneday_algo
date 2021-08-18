#include <iostream>
#include <queue>
using namespace std;
/*
Queue 같은곳에다가 A 와 B 의 움직인 곳을 각각 저장해놓기
배터리충전 하는곳 2차원 배열로 저장. 겹치는 부분은 어떻게 저장 ?
	-> 어짜피 두개만 있으면 되니깐 3차원 ?
	-> 음수로 표현해서 따로저장 ?
	-> 절반만 저장 (싹다 폐지)
1. Queue에 A 와 B 움직일 예정인 곳을 각각 저장하기
2. A, B, C 기지국의 위치를 각 저장하기 (x, y, 전파거리, 배터리 세기, 방문했는지)
3. Queue에서 빼면서 A, B, C 기지국에 닿는지 확인하고 그때 가장 배터리 충전 고르기
*/
struct BC
{
	int x;
	int y;
	int dis;
	int power;
	bool AisVisited;
	bool BisVisited;
};

int T, M, A, tmp, amax, bmax, maxv, res;
queue <int> a;
queue <int> b;
int dx[] = {0, 0, 1, 0, -1 };
int dy[] = {0, -1, 0, 1, 0 };
bool flag;


int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		cin >> M >> A;
		res = 0;
		int Ax = 1, Ay = 1, Bx = 10, By = 10;
		for (int i = 0; i < M; i++) {
			cin >> tmp;
			a.push(tmp);
		}			// a 의 이동 입력
		for (int i = 0; i < M; i++) {
			cin >> tmp;
			b.push(tmp);
		}			// b 의 이동 입력

		struct BC* bc = new BC[A];
		for (int i = 0; i < A; i++) {
			int x, y, dis, power;
			cin >> x >> y >> dis >> power;
			bc[i].x = x;
			bc[i].y = y;
			bc[i].dis = dis;
			bc[i].power = power;
			bc[i].AisVisited = false;
			bc[i].BisVisited = false;
		}			// 기지국 정보 입력까지 입력 끝

		for (int i = 0; i <= M; i++) {
			amax = 0, bmax = 0;
			flag = false;
			maxv = 0;
			for (int j = 0; j < A; j++) {
				bc[j].AisVisited = false;
				bc[j].BisVisited = false;
			}

			for (int j = 0; j < A; j++) {	// 각 기지국이 거리안에 들어온다면 visit 표시
				if ((abs(Ax - bc[j].x) + abs(Ay - bc[j].y) <= bc[j].dis)) {
					bc[j].AisVisited = true;
				}
				if ((abs(Bx - bc[j].x) + abs(By - bc[j].y) <= bc[j].dis)) {
					bc[j].BisVisited = true;
				}
			}

			// 이중 for문으로 전체 기지국에 저장된 정보로 탐색
			for (int k = 0; k < A; k++) {
				for (int j = 0; j < A; j++) {
					if (bc[k].AisVisited && bc[j].BisVisited) {	
						if (k == j) {
							if (maxv < bc[k].power)
								maxv = bc[k].power;
						}
						else {
							if (maxv < (bc[k].power + bc[j].power))
								maxv = (bc[k].power + bc[j].power);
						}
					}
					else if (bc[k].AisVisited && !bc[j].BisVisited) {
						if (maxv < bc[k].power)
							maxv = bc[k].power;
					}
					else if (!bc[k].AisVisited && bc[j].BisVisited) {
						if (maxv < bc[j].power)
							maxv = bc[j].power;
					}

				}
			}
			if (!a.empty()) {
				Ax += dx[a.front()];
				Ay += dy[a.front()];
				Bx += dx[b.front()];
				By += dy[b.front()];
				a.pop();
				b.pop();
			}
			
			res += maxv;
		}


		cout << "#" << TC << " " << res << "\n";
	}

}