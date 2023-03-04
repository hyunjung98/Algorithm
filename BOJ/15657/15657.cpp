#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 10

int N, M;
int arr[MAX];
int aws[MAX];

void func(int num, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << aws[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = num; i < N; i++)
	{
		aws[cnt] = arr[i];
		func(i, cnt + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);
	func(0, 0);

	return 0;
}