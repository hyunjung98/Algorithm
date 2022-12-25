#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 101

vector<int> vec[MAX];	// 인접리스트
bool visited[MAX];		// 방문처리 배열

int comp, edge, cnt;

// 재귀 DFS 사용
void Dfs(int v)
{
	visited[v] = true;	// 방문처리
	
	// 컴퓨터와 연결되어 있는 수만큼 반복하고 카운트 증가
	for (int i = 0; i < vec[v].size(); i++)
	{
		int next = vec[v][i];

		if (visited[next] == false)
		{
			Dfs(next);
			cnt++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> comp;
	cin >> edge;

	// 인접 리스트에 값 집어넣기
	for (int i = 0; i < edge; i++)
	{
		int from, to;
		cin >> from >> to;

		vec[from].push_back(to);
		vec[to].push_back(from);
	}

	// 방문 배열 초기화 후 DFS 실행
	memset(visited, 0, sizeof(visited));
	Dfs(1);
	cout << cnt;;

	return 0;
}