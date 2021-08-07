#include <iostream>
#include <stack>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	int N;
	char tmp;
	stack<char>s;
	bool flag;
	for (int TC = 1; TC <= 10; TC++) {
		flag = false;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			if (flag)
				continue;
			if (tmp == '(' || tmp == '{' || tmp == '[' || tmp == '<')
				s.push(tmp);
			else if (tmp == ')')
			{
				if (s.top() == '(')
					s.pop();
				else
					flag = true;
			}
			else if (tmp == '}')
			{
				if (s.top() == '{')
					s.pop();
				else
					flag = true;
			}
			else if (tmp == ']')
			{
				if (s.top() == '[')
					s.pop();
				else
					flag = true;
			}
			else if (tmp == '>')
			{
				if (s.top() == '<')
					s.pop();
				else
					flag = true;
			}

		}
		if (flag || s.size() != 0) {
			cout << "#" << TC << " 0\n";
		}
		else
			cout << "#" << TC << " 1\n";
		while (!s.empty()) s.pop();
	}
}