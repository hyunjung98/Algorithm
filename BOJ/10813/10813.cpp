#include <iostream>
using namespace std;

int n, m;
int arr[101] = { 0, };

void p()
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
}

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
		int first, second, temp;
		cin >> first >> second;
		temp = arr[first - 1];
		arr[first - 1] = arr[second - 1];
		arr[second - 1] = temp;
	}
	p();
	return 0;
}