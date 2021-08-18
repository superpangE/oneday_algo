#include <iostream>
#include <queue>
using namespace std;
/*
Queue ���������ٰ� A �� B �� ������ ���� ���� �����س���
���͸����� �ϴ°� 2���� �迭�� ����. ��ġ�� �κ��� ��� ���� ?
	-> ��¥�� �ΰ��� ������ �Ǵϱ� 3���� ?
	-> ������ ǥ���ؼ� �������� ?
	-> ���ݸ� ���� (�ϴ� ����)
1. Queue�� A �� B ������ ������ ���� ���� �����ϱ�
2. A, B, C �������� ��ġ�� �� �����ϱ� (x, y, ���İŸ�, ���͸� ����, �湮�ߴ���)
3. Queue���� ���鼭 A, B, C �������� ����� Ȯ���ϰ� �׶� ���� ���͸� ���� ����
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
		}			// a �� �̵� �Է�
		for (int i = 0; i < M; i++) {
			cin >> tmp;
			b.push(tmp);
		}			// b �� �̵� �Է�

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
		}			// ������ ���� �Է±��� �Է� ��

		for (int i = 0; i <= M; i++) {
			amax = 0, bmax = 0;
			flag = false;
			maxv = 0;
			for (int j = 0; j < A; j++) {
				bc[j].AisVisited = false;
				bc[j].BisVisited = false;
			}

			for (int j = 0; j < A; j++) {	// �� �������� �Ÿ��ȿ� ���´ٸ� visit ǥ��
				if ((abs(Ax - bc[j].x) + abs(Ay - bc[j].y) <= bc[j].dis)) {
					bc[j].AisVisited = true;
				}
				if ((abs(Bx - bc[j].x) + abs(By - bc[j].y) <= bc[j].dis)) {
					bc[j].BisVisited = true;
				}
			}

			// ���� for������ ��ü �������� ����� ������ Ž��
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