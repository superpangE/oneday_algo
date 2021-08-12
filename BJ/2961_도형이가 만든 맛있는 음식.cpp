#include <iostream>
#include <cstdlib>
using namespace std;
int si[11], ss[11], ressi, resss, minv = 2147483647;
int num = 1;
int main()
{
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> si[i];
		cin >> ss[i];
		num *= 2;
	}
	num--;
	for (int i = 1; i <= num; i++) {
		ressi = 1; resss = 0;
		for (int j = 0; j < T; j++) {
			if ((i & 1 << j) != 0) {
				ressi *= si[j];
				resss += ss[j];
			}
		}
		if (minv > abs(ressi - resss))
			minv = abs(ressi - resss);
	}
	cout << minv;
	
}