#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 102

vector<int> graph[MAX];
bool visited[MAX];

// �ʱ�ȭ �Լ�
void Init()
{
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < MAX; i++)
	{
		graph[i].clear();
	}
}

// ��ġ�� �Ÿ� ��ȯ�ϴ� �Լ�
int GetDistance(pair<int, int> p1, pair<int, int> p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void Dfs(int v)
{
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++)
	{
		int next = graph[v][i];
		if (!visited[next])
			Dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while(T--)
	{
		Init();

		int n;
		vector<pair<int, int>> vec;
		cin >> n;

		for (int i = 0; i < n+2; i++)
		{
			int x, y;
			cin >> x >> y;
			vec.push_back({ x, y });
		}

		// �Ÿ��� 1000 ������ ��� ��ġ ����
		for (int i = 0; i < n+2; i++)
		{
			for (int j = i+1; j < n+2; j++)
			{
				int dis = GetDistance(vec[i], vec[j]);
				if (dis <= 50 * 20)
				{
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		Dfs(0);	// ������ Ž���ϱ�

		// ���������� happy, �ƴϸ� sad
		if (visited[n+1])
			cout << "happy\n";
		else
			cout << "sad\n";

	}

	return 0;
}