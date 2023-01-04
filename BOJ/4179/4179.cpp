#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001
#define _R first
#define _C second

char map[MAX][MAX];
int visited[MAX][MAX] = { 0, };
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int R, C;

queue<pair<int, int>> qPerson;
queue<pair<int, int>> qFire;

int Bfs()
{
	while (!qPerson.empty())
	{
		int qFireSize = qFire.size();
		for (int size = 0; size < qFireSize; size++)
		{
			pair<int, int> cur = qFire.front();
			qFire.pop();
			for (int i = 0; i < 4; i++)
			{
				int nr = cur._R + dr[i];
				int nc = cur._C + dc[i];

				if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if (map[nr][nc] == '.' && visited[nr][nc] == 0)
				{
					qFire.push({ nr, nc });
					visited[nr][nc] = -2;
				}
			}
		}

		int qPersonSize = qPerson.size();
		for (int size = 0; size < qPersonSize; size++)
		{
			pair<int, int> cur = qPerson.front();
			qPerson.pop();
			for (int i = 0; i < 4; i++)
			{
				int nr = cur._R + dr[i];
				int nc = cur._C + dc[i];

				if (nr < 0 || nr >= R || nc < 0 || nc >= C)
					return visited[cur._R][cur._C];
				if (map[nr][nc] == '.' && visited[nr][nc] == 0)
				{
					qPerson.push({ nr, nc });
					visited[nr][nc] = visited[cur._R][cur._C] + 1;
				}
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		cin >> map[i];
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'J')
			{
				qPerson.push({ i, j });
				visited[i][j] = 1;
			}
			else if (map[i][j] == 'F')
			{
				qFire.push({ i, j });
				visited[i][j] = -2;
			}
		}
	}

	
	int result = Bfs();
	

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << visited[i][j];
		}
		cout << endl;
	}



	if (result == -1)
		cout << "IMPOSSIBLE";
	else
		cout << result;

	return 0;
}