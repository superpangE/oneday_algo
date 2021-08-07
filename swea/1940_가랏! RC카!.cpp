#include <iostream>
using namespace std;
int main()
{
	int TC, num;
	cin >> TC;
	for (int T = 1; T <= TC; T++) {
		int res = 0, type = 0, sec = 0, speed = 0;

		cin >> num;
		for (int t = 0; t < num; t++) {
			cin >> type;
			if (type == 0)
			{
				res += speed;
				continue;
			}
			cin >> sec;
			if (type == 1) {
				speed += sec;
				res += speed;
			}
			else if (type == 2) {
				speed -= sec;
				if (speed <= 0)
					speed = 0;
				res += speed;
			}
		}

		cout << "#" << TC << " " << res << "\n";
	}
}