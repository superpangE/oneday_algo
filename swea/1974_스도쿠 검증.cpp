#include <iostream>
using namespace std;
int T, arr[10][10], flag[10];
int chk_su() {
	for (int i = 0; i < 9; i++) {				// flag 가로 확인
		for (int j = 0; j < 9; j++) {	
//			cout << "arr : " << arr[i][j] << "\n";
//			cout << flag[arr[i][j]] << "\n";
//			cout << "flag[arr[" << i << "][" << j << "]] : " << flag[arr[i][j]]<<"\n";
			if (!(flag[arr[i][j]]))
				flag[arr[i][j]]++;
			else
				return (1);
		}
		for (int j = 0; j < 10; j++) {
			flag[j] = 0;
		}

		for (int j = 0; j < 9; j++) {			// flag 세로 확인
			if (!flag[arr[j][i]])
				flag[arr[j][i]]++;
			else
				return (1);
		}
		for (int j = 0; j < 10; j++) {
			flag[j] = 0;
		}

		//네모로 확인
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				for (int a = i; a < i + 3; a++) {
					for (int b = j; b < j + 3; b++) {
						if (!flag[arr[a][b]])
							flag[arr[a][b]]++;
						else
							return (1);
					}
				}
				for (int k = 0; k < 10; k++)
					flag[k] = 0;
			}
		}

	}
	return (0);
}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				cin >> arr[i][j];
		if (chk_su())
			cout << "#" << TC << " 0\n";
		else cout << "#" << TC << " 1\n";

		for (int i = 0; i < 10; i++)
			flag[i] = 0;
	}
}