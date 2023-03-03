#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 9
int N, M;
int arr[MAX];
vector<int> vec;

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

	for (int i = 0; i < N; i++)
	{
		arr[cnt] = vec[i];
		Dfs(cnt + 1);
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
	Dfs(0);

	return 0;
}