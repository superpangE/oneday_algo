#include <iostream>
using namespace std;
long long X1, X2, Y1, Y2, Xr, Yr;
int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> X1 >> X2 >> Xr >> Y1 >> Y2 >> Yr;
	if (((X1 - Y1) * (X1 - Y1)) + ((X2 - Y2) * (X2 - Y2)) < (Xr + Yr)*(Xr + Yr)) cout << "YES";
	else cout << "NO";
}