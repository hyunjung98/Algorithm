#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>

#define MAX 101
#define X first
#define Y second

using namespace std;

char board[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N, M;				// 가로, 세로
char color;				// 병사의 옷 색 
int white, blue, cnt;	// 해당 색상 병사의 위력, 병사의 수

queue<pair<int, int>> q;

int Bfs(int x, int y, char color)
{
	cnt = 1;
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

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (board[nx][ny] != color || visited[nx][ny]) continue;

			q.push({ nx, ny });
			visited[nx][ny] = true;
			cnt++;
		}
	}

	// 병사의 수를 제곱하여 위력을 구하여 반환
	int power = pow(cnt, 2);
	return power;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 'W' && !visited[i][j])
			{
				color = board[i][j];
				white += Bfs(i, j, color);
			}

			else if (board[i][j] == 'B' && !visited[i][j])
			{
				color = board[i][j];
				blue += Bfs(i, j, color);
			}
		}
	}
	cout << white << ' ' << blue;
}
