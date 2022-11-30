#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX 26
#define _X first
#define _Y second

using namespace std;

int board[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N, cnt;  // 지도의 크기, 집의 개수
vector<int> vecHouseNum;

void Dfs(int x, int y)
{
	cnt++;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (board[nx][ny] == 1 && !visited[nx][ny])
		{
			visited[nx][ny] = true;
			Dfs(nx, ny);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	string str;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			// string으로 받으면 아스키코드 값으로 배열에 넣어지기 때문에 '0'(48)을 빼줘야 함
			board[i][j] = str[j] - '0';
		}
	}

	// 방문 처리 배열  false로 초기화
	memset(visited, false, size(visited));

	int complex = 0;	// 단지 수
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 1 && !visited[i][j])
			{
				visited[i][j] = true;
				Dfs(i, j);
				vecHouseNum.push_back(cnt);
				cnt = 0;
				complex++;
			}
		}
	}

	cout << complex << '\n';	// 단지수 출력

	sort(vecHouseNum.begin(), vecHouseNum.end());	// 오름차순 정렬 
	for (int i = 0; i < vecHouseNum.size(); i++)
	{
		cout << vecHouseNum[i] << '\n';	// 단지 내 집의 수
	}

	return 0;
}

