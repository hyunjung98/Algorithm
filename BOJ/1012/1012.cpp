#include <iostream>
#include <queue>
#include <cstring>

#define X first
#define Y second
#define MAX 51

using namespace std;

int board[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// T: 테스트 케이스 개수, M: 가로, N: 세로, K: 배추 개수
int T, M, N, K;

queue<pair<int, int>> q;

void Bfs(int x, int y)
{
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            // 배열 벗어나면 탐색 안 함
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            // 배추 없거나 이미 방문한 곳은 탐색 안 함
            if (board[nx][ny] != 1 || visited[nx][ny])
                continue;

            // 그 외 인접한 공간에 배추 있으면 큐에 넣고 방문 처리
            q.push({ nx, ny });
            visited[nx][ny] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;
        // 배열 초기화
        memset(board, 0, sizeof(board));
        memset(visited, false, sizeof(visited));

        // 배추가 있는 좌표값 입력 받기
        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        // 지렁이의 수
        int cnt = 0;

        // 배열 탐식하며 배추가 있고 방문하지 않았다면 BFS 실행
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                if (board[n][m] == 1 && !visited[n][m])
                {
                    Bfs(n, m);
                    cnt++;  // 한 배추 구역의 탐색이 종료되면 지렁이 수 1 증가
                }
            }
        }

        /*for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                cout << board[n][m] << ' ';
            }
            cout << endl;
        }*/

        // 구역의 수 출력
        cout << cnt << "\n";
    }
}
