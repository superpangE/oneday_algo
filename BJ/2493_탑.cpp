#include <iostream>
#include <stack>
using namespace std;
stack<pair<int, int>>s;
stack<pair<int, int>>cp;
int main()
{
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	int T, num;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		cin >> num;
		//if (!s.empty() && s.top().first < num)
		//	s.pop();
		//s.push({ num, TC });
		while (!s.empty())
		//while (s.size() > 1)
		{
			if (num <= s.top().first) {
				cout << s.top().second << " ";
				s.push({ num,TC });
				break;
			}
			s.pop();
		}


		if (s.empty()) {
			s.push({ num, TC });
			cout << "0 ";
		}
		//cp = s;
		//cp.pop();
		//while (!cp.empty()) {
		//	if (cp.top().first >= s.top().first) {
		//		cout << cp.top().second << " ";
		//		break;
		//	}
		//	cp.pop();
		//}
	}
}