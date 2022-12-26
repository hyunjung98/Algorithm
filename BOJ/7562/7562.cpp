#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 301
#define _X first
#define _Y second

int board[MAX][MAX];
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int t, l; // 테스트 케이스, 한 변의 길이
int posX, posY, tPosX, tPosY;
queue<pair<int, int>> q;

// 배열 초기화, 큐 비워주는 함수
void Reset(int side)
{       
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            board[i][j] = 0;
        }
    }
    while (!q.empty()) q.pop();
}

int Bfs()
{
    while (!q.empty())
    {
        // 이동하려는 좌표가 시작 좌표면 안 움직여도 된다.
        if (posX == tPosX && posY == tPosY) return 0;

        // 현재 위치 x, y 저장
        pair<int, int> cur = q.front();
        int x = cur._X;
        int y = cur._Y;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 벗어나거나 이미 방문했으면 무시
            if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            if (board[nx][ny] != 0) continue;

            // 다음 위치가 이동하려던 위치면 이동 횟수 반환
            if (nx == tPosX && ny == tPosY) return board[x][y] + 1;
            
            q.push({ nx, ny });
            board[nx][ny] = board[x][y] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (true)
    {
        // 테스트 케이스 횟수만큼 다 입력하면 반복문 벗어나기
        if (t == 0) break;  
        cin >> l;
        Reset(l);

        cin >> posX >> posY >> tPosX >> tPosY;
        // 현재 위치 큐에 넣고 Bfs 실행 후 이동 횟수 출력
        q.push({ posX, posY });
        int result = Bfs();
        cout << result << '\n';
        t--;
    }

    return 0;
}
