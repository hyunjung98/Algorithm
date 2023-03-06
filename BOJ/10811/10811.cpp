#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int arr[101] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;
		reverse(arr + start - 1, arr + end);
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}