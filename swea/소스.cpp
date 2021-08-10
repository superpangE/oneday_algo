#include <iostream>
#include <vector>
using namespace std;
int arr[1001], maxv, kg;
vector<int>v;
void rec(int idx, int N) {
	if (idx >= N) {
		if(v.size() == 2)
			if (v[0] + v[1] <= kg)
				if (maxv < v[0] + v[1])
					maxv = v[0] + v[1];
		return;
	}
	if (v.size() >= 2) {
		if (v[0] + v[1] <= kg)
			if (maxv < v[0] + v[1])
				maxv = v[0] + v[1];
		return;
	}
	v.push_back(arr[idx]);
	rec(idx + 1, N);
	v.pop_back();
	rec(idx + 1, N);
}

int main()
{
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	int T, num;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		maxv = -1;
		cin >> num >> kg;
		for (int i = 0; i < num; i++)
			cin >> arr[i];
		rec(0, num);
		cout << "#" << TC << " " << maxv << "\n";
	}
}