#include <iostream>

using namespace std;
#define MAX 10

int N, M;
int arr[MAX];
bool isUsed[MAX];

void Dfs(int num, int cnt)
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
	
	for (int i = num; i <= N; i++)
	{
		if (isUsed[i-1]) continue;
		arr[cnt] = i;
		isUsed[i] = true;
		Dfs(i, cnt + 1);
		isUsed[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	Dfs(1, 0);
	return 0;
}