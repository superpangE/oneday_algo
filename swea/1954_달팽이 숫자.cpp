#include <iostream>
using namespace std;
int arr[11][11];
void move(int x, int y, int dir, int write, int num) // dir -> 0: 위  1: 오른  2: 아래  3: 왼
{
    arr[x][y] = write;

    if (write > num * num - 1)
        return;
    if (dir == 1) {
        if ((y + 1 < num) && arr[x][y + 1] == 0)
            move(x, y + 1, 1, ++write, num);
        else
            move(x + 1, y, 2, ++write, num);
    }
    else if (dir == 2) {
        if ((x + 1 < num) && arr[x + 1][y] == 0)
            move(x + 1, y, 2, ++write, num);
        else
            move(x, y - 1, 3, ++write, num);
    }
    else if (dir == 3) {
        if ((y - 1 >= 0) && arr[x][y - 1] == 0)
            move(x, y - 1, 3, ++write, num);
        else
            move(x - 1, y, 0, ++write, num);
    }
    else if (dir == 0) {
        if ((x - 1 >= 0) && arr[x - 1][y] == 0)
            move(x - 1, y, 0, ++write, num);
        else
            move(x, y + 1, 1, ++write, num);
    }
}
int main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        int num;
        cin >> num;
        cout << "#" << TC << "\n";
        if (num == 1) {
            cout << "1\n";
            continue;
        }
        else if (num == 2)
        {
            cout << "1 2\n4 3\n";
            continue;
        }
        move(0, 0, 1, 1, num);
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                cout << arr[i][j] << " ";
                arr[i][j] = 0;
            }
            cout << "\n";
        }
    }
}