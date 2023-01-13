#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 101
#define _X first
#define _Y second

int board[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, M, hour;

queue<pair<int, int>> q;

// 2로 변경한 외부 공기를 다시 0으로 바꿔주는 함수
void ResetAir()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 2)
				board[i][j] = 0;
		}
	}
}

// 배열에 치즈가 존재하지 않을 경우 true, 존재할 경우 false 반환
bool HasAllMelted()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] != 0)
				return false;
		}
	}
	return true;

}

// 치즈 사방에 공기가 있을 경우 카운트 증가시킨 후, 두면이 공기라면 치즈를 녹임
void MeltCheese()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int airCount = 0;
			if (board[i][j] != 1) continue;
			if (board[i + 1][j] == 2) airCount++;
			if (board[i - 1][j] == 2) airCount++;
			if (board[i][j + 1] == 2) airCount++;
			if (board[i][j - 1] == 2) airCount++;

			if (airCount >= 2)
			{
				board[i][j] = 0;
			}
		}
	}
}

void Bfs()
{
	q.push({ 0, 0 });
	visited[0][0] = true;
	hour++;

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

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] != 0 || visited[nx][ny]) continue;
			// 공기를 2로 바꿔줌
			q.push({ nx, ny });
			board[nx][ny] = 2;
			visited[nx][ny] = true;
		}
	}
}


int main()
{
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	while (true)
	{
		if (HasAllMelted())
		{
			cout << hour;
			break;
		}

		memset(visited, 0, sizeof(visited));
		Bfs();
		MeltCheese();
		ResetAir();
	}

	return 0;
}