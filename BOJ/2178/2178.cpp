#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 101
#define _X first
#define _Y second

int maze[MAX][MAX];
int visited[MAX][MAX];

int N, M;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

void Bfs(int x, int y)
{
	visited[x][y] = 1;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		int curX = cur._X;
		int curY = cur._Y;

		for (int i = 0; i < 4; i++)
		{
			int nx = cur._X + dx[i];
			int ny = cur._Y + dy[i];

			// 범위 벗어나거나 지나갈 수 없는 곳, 방문한 곳은 처리 X
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (maze[nx][ny] == 0 || visited[nx][ny] != 0) continue;
			q.push({ nx, ny });
			visited[nx][ny] = visited[curX][curY] + 1;
		}
	}

	// (N, M)에 도달했을 때의 값 출력
	cout << visited[N - 1][M - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			maze[i][j] = str[j] - '0';
		}
	}

	memset(visited, 0, sizeof(visited));

	q.push({ 0, 0 });
	Bfs(0, 0);

	return 0;
}
