#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char>s;
int main()
{
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	int T;
	char tmp;
	bool flag;
	string text;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int res = 0;
		flag = false;
		cin >> text;
		for (int i = 0; i < text.length(); i++) {
			tmp = text[i];
			if (tmp == '(') {
				s.push(tmp);
				flag = false;
			}
			else {
				s.pop();
				if (!flag)
					res += s.size();
				else
					res++;
				flag = true;
			}
		}
		cout << "#" << TC << " " << res << "\n";
	}
}