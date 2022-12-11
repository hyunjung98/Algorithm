#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 1000001
#define _X first
#define _Y second

int visited[MAX];

int F;		// 꼭대기 층
int S;		// 강호가 있는 층
int G;		// 이동하려는 층
int U, D;	// 위로 몇 층? 아래로 몇 층?

queue<int> q;

void Bfs()
{
	q.push(S);
	visited[S] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		
		// 도착했으면 이동횟수 출력
		if (cur == G)
		{
			cout << visited[cur];
			return;
		}

		for (int i = 0; i < 2; i++)
		{
			// 아래, 위 방향 벡터
			int dir[2] = { -D, U };
			int next = cur + dir[i];

			// 1층 미만/최상층 이상, 방문한 곳이라면 무시한다.
			if (next <= 0 || next > F || visited[next] != -1) continue; 
			// 이동 횟수를 증가시켜 값을 저장시킨다.
			visited[next] = visited[cur] + 1;
			q.push(next);
		}
	}
	// 이동하려는 층에 도달하지 못했을 경우 출력된다.
	cout << "use the stairs";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> F >> S >> G >> U >> D;
	
	// 방문 처리를 위해 전부 -1로 초기화한다.
	memset(visited, -1, sizeof(visited));

	Bfs();

	return 0;
}