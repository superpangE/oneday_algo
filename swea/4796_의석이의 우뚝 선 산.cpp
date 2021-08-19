#include <iostream>
using namespace std;
/*
* TC 를 받고 받은 TC 만큼 arr에 삽입
* arr를 0번째 인덱스부터 찾으면서, 오른다면 잠시 곱하기위해 따로 저장
* 내려간다면 내려갔다가 (idx + 1) 이 커질 때 까지 따로 저장
* 올라간다고 한다면 해당 인덱스는 잠시 저장한 뒤, 상위 두개를 곱해줌
* 다음 인덱스로
*/
int T, N, *arr, tmp, ucnt, dcnt, res;
bool flag;

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		ucnt = dcnt = res = 0;
		flag = false;
		cin >> N;
		arr = new int[N];
		for (int i = 0; i < N; i++)
			cin >> arr[i];		// 입력 완료

		for (int i = 0; i < N - 1; i++) {
			tmp = arr[i];
			if (!flag && arr[i] < arr[i + 1]) {
				ucnt++;
			}
			else if (flag && arr[i] > arr[i + 1]) {
				dcnt++;
			}
			else if (flag && arr[i] < arr[i + 1]) {
				flag = false;
				res += (ucnt * dcnt);
				ucnt = 1;
				dcnt = 0;
			}
			else if (!flag && arr[i] > arr[i + 1]) {
				flag = true;
				dcnt++;
			}
			else if (!flag && arr[i] < arr[i + 1]) {
				flag = false;
			}
		}
		if (flag) res += (ucnt * dcnt);
		cout << "#" << TC << " " <<  res << "\n";
	}
}