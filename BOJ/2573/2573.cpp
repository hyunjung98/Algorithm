#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 301
#define _X first
#define _Y second

int map[MAX][MAX];
int copyMap[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N, M, year;
bool isSeparated = false;

queue<pair<int, int>> q;

void p()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Bfs()
{
	while (!q.empty())
	{
		auto cur = q.front();
		int x = cur._X;
		int y = cur._Y;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (map[nx][ny] == 0 || visited[nx][ny]) continue;
			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
}

bool HasAllMelt()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] != 0) return false;
		}
	}
	return true;
}

void MeltIceberg()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int cnt = 0;
			if (copyMap[i][j] == 0) continue;
			if (copyMap[i + 1][j] == 0) cnt++;
			if (copyMap[i - 1][j] == 0) cnt++;
			if (copyMap[i][j + 1] == 0) cnt++;
			if (copyMap[i][j - 1] == 0) cnt++;

			map[i][j] = map[i][j] - cnt;
			if (map[i][j] < 0) map[i][j] = 0;
		}
	}
	year++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	while (true)
	{
		if (HasAllMelt()) break;

		int cnt = 0;
		int result = 0;
		
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] > 0 && !visited[i][j])
				{
					visited[i][j] = true;
					q.push({ i, j });
					Bfs();
					cnt++;
				}
				copyMap[i][j] = map[i][j];
			}
		}

		if (cnt > 1)
		{
			isSeparated = true;
			break;
		}

		MeltIceberg();
	}

	if (isSeparated)
		cout << year;
	else
		cout << 0;

	return 0;
}