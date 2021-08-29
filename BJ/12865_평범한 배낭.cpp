#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
* 무게 w와 가치 v 를 가진 구조체를 만든다
* 구조체를 자료형으로 갖는 배열을 만듬
* 부분집합으로 무게 w 를 넘지않을때 최대 v 를 찾는다
* 
* - 시간초과남 - 
* + powerset 함수에서 매개변수 두개넘겨서 바로 확인하는 방식
* + powerset 함수에서 weight 뿐만 아니라 value 도 넘겨서 한번에 확인
* + 함수에 들어가서 확인하는게 아니라 들어가기 전에 확인하는 방식
* 
* - 백트래킹으로 푸는 문제가 아님 -
* + dp로 점화식 세워서 해야하는 문제
* + dp[현재 위치][현재 무게] = (내가 가져올 수 있는 최대 가치) 로 저장
*/
struct box {
	int w;
	int v;
};
int N, K, res, dp[101][100001];
box *arr;
int powerset(int k, int bw) {
	
	if (dp[k][bw] >= 0) return (dp[k][bw]);
	if (k == N) return (0);
	
	dp[k][bw] = powerset(k + 1, bw);	// 현재 인덱스 물건 선택을 안할 때
	if (bw + arr[k].w <= K)				// 현재 인덱스 물건 선택 할 때
		dp[k][bw] = max(dp[k][bw], powerset(k + 1, bw + arr[k].w) + arr[k].v);

	return (dp[k][bw]);		// 현재 위치에서, 현재 무게까지 들었을때 앞으로 들 수 있는 최대 무게

}
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	arr = new box[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i].w;
		cin >> arr[i].v;
	}		// 입력 완료
	memset(dp, -1, sizeof(dp));		// dp 는 통상적으로 -1로 초기화
	cout << powerset(0, 0);
}