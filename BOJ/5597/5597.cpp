#include <iostream>
#include <algorithm>

using namespace std;

int num;
int students[31] = { 0, };
int ans[2] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 28; i++)
	{
		cin >> num;
		students[num] = num;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (students[i] == 0)
		{
			cout << i << '\n';
		}
	}

    return 0;
}