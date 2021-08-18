#include <iostream>
#include <vector>
using namespace std;
/*
	1. 조합으로 총 N 개에서 (N/2) 개를 고른다
	2. N/2 만큼 고른 재료들을 두개씩 순열을 골라 arr[i][j] 의 값을 다 더한다
	3. 가장 큰 값을 고른다
	4. 최대일때가 총 16개의 재료가 나올때 : (조합으로 약 12,000회)
	5. 나머지 8개중 2개씩 고르는 횟수 : 56회
	100만 이하라서 괜찮을듯
*/

int arr[16][16], T, N, *saveBox1, saveBox2[2], *saveBox3, saveBox4[2], Amax, Bmax, minv;
bool chk[16];
vector<int>v;

void sum(int box[], int sel) {
	if (sel == 1)
		Amax += arr[box[0]][box[1]];
	else
		Bmax += arr[box[0]][box[1]];
}

void perm(int depth, int Boxs[], int inputbox[], int find) {	// 순열로 고른 값들을 saveBox2 에 저장되어 있음
	if (depth == 2) {
		sum(inputbox, find);
		return;
	}
	
	for (int i = 0; i < N/2; i++) {
		if (!chk[i]) {
			chk[i] = true;
			inputbox[depth] = Boxs[i];
			perm(depth + 1, Boxs, inputbox, find);
			chk[i] = false;
		}
	}
}

void comb(int depth, int next) {
	if (depth == N / 2) {
		// 뉴 함수 -> saveBox 에 저장되어 있는 값들을 순열로 푼다. bool chk 초기화 하기
		int k = 0;
		Amax = 0, Bmax = 0;
		for (int i = 0; i < N; i++) {		// saveBox1 에 없는값들 saveBox3 에 저장하기
			bool flag = false;
			for (int j = 0; j < N/2; j++) {
				if (saveBox1[j] == i)
					flag = true;
			}
			if (!flag) saveBox3[k++] = i;
		}
		perm(0, saveBox1, saveBox2, 0);
		perm(0, saveBox3, saveBox4, 1);

		if (abs(Amax - Bmax) < minv)
			minv = abs(Amax - Bmax);
		return;
	}
	for (int i = next; i < N; i++) {
		saveBox1[depth] = i;
		comb(depth + 1, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];	// 입력 완료

		// N 개중에 N/2 만큼을 조합으로 구함
		saveBox1 = new int[N / 2];
		saveBox3 = new int[N / 2];
		minv = 2147483647;
		comb(0, 0);
		cout << "#" << TC << " " << minv << "\n";
	}
}