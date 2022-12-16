#include <iostream>

using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i < N; i++)
	{
		int temp = i;
		int sum = i;

		while (temp > 0)
		{
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == N)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}