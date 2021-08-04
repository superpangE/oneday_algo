#include <iostream>
using namespace std;
int T, x, y, tx, ty, num, dir;  // 0 : ╩С    1 : ©Л    2 : го    3 : аб
char tmp;
int main()
{
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		cin >> x >> y;
		char** arr = new char*[x];
		for (int i = 0; i < x; i++) {
			arr[i] = new char[y];
		}
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				cin >> tmp;
				arr[i][j] = tmp;
				if (tmp == '<' || tmp == '>' || tmp == '^' || tmp == 'v') {
					tx = i;
					ty = j;
					if (tmp == '<')
						dir = 3;
					else if (tmp == '>')
						dir = 1;
					else if (tmp == '^')
						dir = 0;
					else if (tmp == 'v')
						dir = 2;
				}
			}
		}
		cin >> num;
		while (num--) {
			cin >> tmp;
			if (tmp == 'U')
			{
				dir = 0;
				if (tx - 1 >= 0 && arr[tx - 1][ty] == '.')
					arr[tx--][ty] = '.';
			}
			else if (tmp == 'D')
			{
				dir = 2;
				if (tx + 1 < x && arr[tx + 1][ty] == '.')
					arr[tx++][ty] = '.';
			}
			else if (tmp == 'L')
			{
				dir = 3;
				if (ty - 1 >= 0 && arr[tx][ty - 1] == '.')
					arr[tx][ty--] = '.';
			}
			else if (tmp == 'R')
			{
				dir = 1;
				if (ty + 1 < y && arr[tx][ty + 1] == '.')
					arr[tx][ty++] = '.';
			}
			else if (tmp == 'S')
			{
				if (dir == 0)
				{
					for (int i = 0; i < x; i++) {
						if ((tx - i) < 0)
							break;
						if (arr[tx - i][ty] == '#' || arr[tx - i][ty] == '*') {
							if (arr[tx - i][ty] == '*')
								arr[tx - i][ty] = '.';
							break;
						}
					}
				}
				else if (dir == 2)
				{
					for (int i = 0; i < x; i++) {
						if ((tx + i) >= x)
							break;
						if (arr[tx + i][ty] == '#' || arr[tx + i][ty] == '*') {
							if (arr[tx + i][ty] == '*')
								arr[tx + i][ty] = '.';
							break;
						}
					}
				}
				else if (dir == 1)
				{
					for (int i = 0; i < y; i++) {
						if ((ty + i) >= y)
							break;
						if (arr[tx][ty + i] == '#' || arr[tx][ty + i] == '*') {
							if (arr[tx][ty + i] == '*')
								arr[tx][ty + i] = '.';
							break;
						}
					}
				}
				else if (dir == 3)
				{
					for (int i = 0; i < y; i++) {
						if ((ty - i) < 0)
							break;
						if (arr[tx][ty - i] == '#' || arr[tx][ty - i] == '*') {
							if (arr[tx][ty - i] == '*')
								arr[tx][ty - i] = '.';
							break;
						}
					}
				}
			}
		}
		if (dir == 0)
			arr[tx][ty] = '^';
		else if (dir == 1)
			arr[tx][ty] = '>';
		else if (dir == 2)
			arr[tx][ty] = 'v';
		else if (dir == 3)
			arr[tx][ty] = '<';
		cout << "#" << TC << " ";
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				cout << arr[i][j];
			}
			cout << "\n";
		}
		
	}
}