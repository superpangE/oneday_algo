#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int N, fir, sec, cnt;
bool *flag;

int main() {
	cin >> N;
	flag = new bool[N];
	memset(flag, false, sizeof(flag));

	for (int i = 0; i < N; i++) {
		cin >> fir >> sec;
		v.push_back(make_pair(fir, sec));
	}	// 입력 완료

	sort(v.begin(), v.end());

	//int last = v[0].second;
	//int cnt = 1;
	//for (int i = 1; i < N; i++) {
	//	if (v[i].first <= last) {
	//		last = min(last, v[i].second);
	//	}
	//	else {
	//		last = v[i].second;
	//		cnt += 1;
	//	}
	//}
	
	for (int i = 0; i < N; i++) {
		if (!flag[i]){
			int last = v[i].second;
			flag[i] = true;
			int j = 1;
			while ((i + j < N) && v[i + j].first <= last) {
				if (v[i + j].second < last)
					last = v[i + j].second;
				flag[i + j] = true;
				j++;
			}
			cnt++;
		}
	}

	cout << cnt;
}