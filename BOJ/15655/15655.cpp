#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10

int N, M;
int arr[MAX];
bool isUsed[MAX];
vector<int> vec;

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
		if (isUsed[i]) continue;
		arr[cnt] = vec[i-1];
		isUsed[i] = true;
		Dfs(i + 1, cnt + 1);
		isUsed[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	Dfs(1, 0);

	return 0;
}