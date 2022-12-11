#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 101

#define _X first.first	
#define _Y first.second
#define _Z second

int board[MAX][MAX][MAX];

int M, N, H;	// 가로, 세로, 높이
int temp = 0;
int day = 0;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

queue<pair<pair<int, int>, int>> q;		// {{M, N}, H} 저장

void Bfs()
{
	while (!q.empty())
	{
		pair<pair<int, int>, int> cur = q.front();
		int x = cur._X;
		int y = cur._Y;
		int z = cur._Z;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			// 범위를 벗어나거나, 토마토가 존재하지 않을 경우 무시
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
			if (board[nx][ny][nz] == -1) continue;

			// 익은 토마토 근처에 익지 않은 토마토가 존재할 경우 큐에 담고 
			if (board[nx][ny][nz] == 0)
			{
				q.push({ {nx, ny}, nz });
				board[nx][ny][nz] = board[x][y][z] + 1;
			}
		}
	}
}

// 현재 배열에 담긴 토마토의 상태를 확인한다.
// 배열에 0이 있을 경우에 익지 않은 토마토가 존재한다는 뜻이다.
// 그 외는 일수를 출력한다.
void CheckBoard()
{
	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				// 만약 익지 않은 토마토가 존재할 경우 -1을 출력한다.
				if (board[i][j][h] == 0)
				{
					cout << -1;
					return;
				}

				// 현재 배열의 값 저장하여 최소 일수를 저장한 값과 비교
				// 만약 현재 배열 값(temp)가 크면 day에 값 덮어씌움
				temp = board[i][j][h];

				if (day < temp)
					day = temp;
			}
		}
	}
	// 익은 토마토가 1이기 때문에 일수를 구하기 위해서는 1을 빼줘야 한다.
	cout << day - 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N >> H;

	// 3차원 배열 입력
	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> board[i][j][h];
			}
		}
	}

	// 익은 토마토가 있으면 해당 위치값을 큐에 저장한다.
	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (board[i][j][h] == 1)
				{
					q.push({ { i, j }, h });
				}
				
			}
		}
	}

	Bfs();
	CheckBoard();

	return 0;
}
