#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 51
#define _X first
#define _Y second

char map[MAX][MAX];
int visited[MAX][MAX] = { 0, };

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

int r, c;
int dis = -1;

void Bfs(int x, int y)
{
	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur._X + dx[i];
			int ny = cur._Y + dy[i];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (map[nx][ny] == 'W' || visited[nx][ny] != 0) continue;

			q.push({ nx, ny });
			visited[nx][ny] = visited[cur._X][cur._Y] + 1;
			if (dis < visited[nx][ny])
				dis = visited[nx][ny];
		}
	}


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = str[j];
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 'L' && visited[i][j] == 0)
			{
				Bfs(i, j);
				memset(visited, 0, sizeof(visited));
			}
		}
	}

	cout << dis - 1;

	return 0;
}