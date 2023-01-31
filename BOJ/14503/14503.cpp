#include <iostream>

using namespace std;

#define MAX 52

int N, M, cnt;
int map[MAX][MAX];

// 북, 동, 남, 서
int forwardDx[] = { -1, 0, 1, 0 };
int forwardDy[] = { 0, 1, 0, -1 };

// 후진했을 경우의 방향 남, 서, 북, 동
int backwardDx[] = { 1, 0, -1, 0 };
int backwardDy[] = { 0, -1, 0, 1 };

int GetNextDir(int dir)
{
	if (dir == 0)
		return 3;
	else
		return dir - 1;
}

void Dfs(int x, int y, int dir)
{
	if (map[x][y] == 1) return;
	// 위치를 청소했을 경우 해당 위치 -1로 변경
	if (map[x][y] == 0)
	{
		map[x][y] = -1;
		cnt++;
	}

	// 현재 위치에서 주변에 청소하지 않은 공간이 있을 때 네방향 탐색
	for (int i = 0; i < 4; i++)
	{
		int nextDir = GetNextDir(dir);
		int nx = x + forwardDx[nextDir];
		int ny = y + forwardDy[nextDir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (map[nx][ny] == 0)
		{
			Dfs(nx, ny, nextDir);
			return;
		}
		else
			dir = nextDir;
	}

	// 네방향 모두 청소가 되어있거나, 벽일 경우의 사방향
	int backwardNx = x + backwardDx[dir];
	int backwardNy = y + backwardDy[dir];

	Dfs(backwardNx, backwardNy, dir);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	int r, c, dir;


	cin >> r >> c >> dir;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	Dfs(r, c, dir);
	cout << cnt;

	return 0;
}