#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 101

vector<int> vec[MAX];
bool visited[MAX];

int n, m, person1, person2;
int result = -1;

void Dfs(int vertex1, int vertex2, int cnt)
{
	visited[vertex1] = true;

	// 찾으면 횟수 저장
	if (vertex1 == vertex2)
	{
		result = cnt;
		return;
	}

	for (int i = 0; i < vec[vertex1].size(); i++)
	{
		int next = vec[vertex1][i];
		
		if (!visited[next])
		{
			Dfs(next, vertex2, cnt + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> person1 >> person2 >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		vec[from].push_back(to);
		vec[to].push_back(from);
	}

	memset(visited, 0, sizeof(visited));
	Dfs(person1, person2, 0);
	cout << result;

	return 0;
}