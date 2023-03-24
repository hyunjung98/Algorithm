#include <iostream>
using namespace std;

int func(int n)
{
	int selfNumber = n;
	while (n != 0)
	{
		selfNumber += n % 10;
		n = n / 10;
	}
	
	return selfNumber;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	bool numbers[10001] = { false };
	int temp = 0;
	for (int i = 1; i <= 10000; i++)
	{
		temp = func(i);
		if (temp <= 10000)
			numbers[temp] = true;
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (!numbers[i])
			cout << i << '\n';
	}

	return 0;
}