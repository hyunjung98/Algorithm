#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 101
#define _X first
#define _Y second

char board[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N;
char color;
int rgbCount, colorBlindCount;

void Bfs(int x, int y, char color)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur._X + dx[i];
            int ny = cur._Y + dy[i];

            if (board[nx][ny] != color || visited[nx][ny]) continue;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            q.push({ nx, ny });
            visited[nx][ny] = true;
        }
    }
}

// bfs 실행하여 총 그림 영역의 수를 반환하는 함수이다.
int GetCount(char arr[][MAX])
{
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            color = arr[i][j];
            if (!visited[i][j] && arr[i][j] == color)
            {
                Bfs(i, j, color);
                cnt++;  
            }
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 크기 입력
    cin >> N;

    // 그림 입력
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
        {
            board[i][j] = str[j];
        }
    }

    // 적록색약이 아닌 사람이 보는 그림 영역의 수 구하기
    rgbCount = GetCount(board);

    // 방문 배열 초기화
    memset(visited, false, sizeof(visited));

    // 적록색약인 사람은 붉은색=초록색으로 인식하기 때문에
    // 초록색 그림이 위치한 곳을 붉은색 그림으로 변경
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 'G')
                board[i][j] = 'R';
        }
    }

    // 적록색약인 사람이 보는 그림 영역의 수 구하기
    colorBlindCount = GetCount(board);

    // 출력
    cout << rgbCount << ' ' << colorBlindCount;
}