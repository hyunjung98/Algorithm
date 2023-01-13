#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 101
#define _X first
#define _Y second

int board[MAX][MAX];
bool visited[MAX][MAX];
int n, m, hour, temp;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool check = false;

queue<pair<int, int>> q;

void Bfs()
{
	q.push({ 0, 0 });
	visited[0][0] = true;
	hour++;
	int cnt = 0;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur._X + dx[i];
			int ny = cur._Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny]) continue;
			if (board[nx][ny] == 0)
			{
				q.push({ nx, ny });
			}
			// 치즈 있으면 녹여주고 치즈 개수 증가
			else
			{
				board[nx][ny] = 0;
				cnt++;
			}
			visited[nx][ny] = true;
		}
	}

	if (cnt == 0)
		check = true;
	//  치즈가 남았다면 현재 남은 치즈 저장
	else
		temp = cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	while (true)
	{
		if (check)
		{
			cout << hour - 1 << '\n' << temp;
			break;
		}
		memset(visited, false, sizeof(visited));
		Bfs();
	}

	return 0;
}