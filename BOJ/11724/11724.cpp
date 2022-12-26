#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001

vector<int> vec[MAX];
bool visited[MAX];

int vertex, edge, from, to, cnt;

void Dfs(int v)
{
	visited[v] = true;

	for (int i = 0; i < vec[v].size(); i++)
	{
		int next = vec[v][i];
		if (!visited[next])
			Dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> vertex >> edge;

	for (int i = 1; i <= edge; i++)
	{
		cin >> from >> to;
		vec[from].push_back(to);
		vec[to].push_back(from);
	}

	for (int i = 1; i <= vertex; i++)
	{
		if (!visited[i])
		{
			Dfs(i);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}