#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 1001
#define _X first
#define _Y second

int board[MAX][MAX];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int M, N;	// 가로, 세로
int maxDay = 0;
int day = 0;

queue<pair<int, int>> q;

void Bfs()
{
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		int x = cur._X;
		int y = cur._Y;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;	// 범위를 벗어났다면
			if (board[nx][ny] == -1) continue;						// 토마토가 없다면

			// 익지 않은 토마토가 있을 경우, 
			if (board[nx][ny] == 0)
			{
				board[nx][ny] = board[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

// 익지 않은 토마토가 있는지 확인하고 모두 익었으면 일수 출력
void CheckBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// 익지 않은 토마토가 있을 때는 -1 출력 후 for문 탈출
			if (board[i][j] == 0)
			{
				cout << -1;
				return;
			}
			// 배열의 값을 저장하는 day 변수가 최대 일수보다 크다면 바꿔준다.
			day = board[i][j];
			if (maxDay < day)
				maxDay = day;
		}
	}
	// 익은 토마토가 1이기 때문에 일수를 구하기 위해서는 1을 빼줘야 한다.
	cout << maxDay - 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 가로, 세로 입력
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// 배열 입력
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 1)
			{
				// 익은 토마토가 있으면 큐에 넣음
				q.push({ i, j });
			}
		}
	}

	Bfs();
	CheckBoard();

	return 0;
}
