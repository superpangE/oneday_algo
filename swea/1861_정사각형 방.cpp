#include <iostream>
using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool isValid(int x, int y, int size) {
    return (x >= 0 && y >= 0 && x < size&& y < size);
}

int move(int x, int y, int num, int** arr, int doit) {
    //int num = arr[0].size();
    for (int i = 0; i < 4; i++) {
        int mx = x + dx[i];
        int my = y + dy[i];

        if (!isValid(mx, my, num))
            continue;
        if (arr[mx][my] == arr[x][y] + 1)
            return (move(mx, my, num, arr, doit + 1));
    }
    return (doit);
}

int main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    int T, num, max, tmp;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        int savearr = 2147483647;
        max = 0;
        cin >> num;
        int** arr = new int* [num];
        for (int i = 0; i < num; i++)
            arr[i] = new int[num];
        // arr 를 num 만큼 2차원 동적배열
        for (int i = 0; i < num; i++)
            for (int j = 0; j < num; j++)
                cin >> arr[i][j];
        // arr 에 입력 끝

        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                tmp =  move(i, j, num, arr, 1);
                if (max < tmp) {
                    max = tmp;
                    savearr = arr[i][j];
                }
                else if (max == tmp && savearr > arr[i][j])
                    savearr = arr[i][j];

            }
        }
        cout << "#" << TC << " " << savearr << " " << max << "\n";
    }
}