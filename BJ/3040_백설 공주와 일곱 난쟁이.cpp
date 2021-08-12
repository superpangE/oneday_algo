#include <iostream>
using namespace std;
int arr[9], res[7], ans[7];
bool v[9];
void comb(int idx, bool isvisit[]) {
	if (idx == 7)
	{
		int num = 0;
		for (int i = 0; i < 7; i++)
			num += res[i];
		if (num == 100)
		{
			for (int i = 0; i < 7; i++) {
				ans[i] = res[i];
			}
		}
		return;
	}

	for (int i = idx; i < 9; i++) {
		if (isvisit[i]) continue;
		res[idx] = arr[i];
		isvisit[i] = true;
		comb(idx + 1, isvisit);
		isvisit[i] = false;
	}
}

int main(){
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	comb(0, v);
	for (int i = 0; i < 7; i++)
		cout << ans[i] << "\n";
}