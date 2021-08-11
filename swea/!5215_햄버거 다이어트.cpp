#include <iostream>
#include <vector>
using namespace std;
int T, N, L, taste, a, b;
vector<pair<int, int>>v;
vector<pair<int, int>>res;

void recu(int n) {
	int tmpkg = 0;
	int tmpcal = 0;
	for (int i = 0; i < res.size(); i++) {
		tmpkg += res[i].second;
		tmpcal += res[i].first;
	}
	if (tmpkg > L)
		return;
	if (tmpcal > taste) {
		taste = tmpcal;
	}

	for (int i = n; i < N - 1; i++) {
		res.push_back(make_pair(v[i].first,v[i].second));
		recu(n + 1);
		res.pop_back();
		recu(n + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		taste = 0;
		cin >> N >> L;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		recu(0);
		cout << "#" << TC << " " << taste << "\n";
		v.clear();
		res.clear();
	}

}