#include <iostream>
using namespace std;
#define MAX 9

int N, M;
int arr[MAX];
bool isUsed[MAX];

void Dfs(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		arr[cnt] = i;
		isUsed[i] = true;
		Dfs(cnt + 1);
		isUsed[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	Dfs(0);
	return 0;
}
