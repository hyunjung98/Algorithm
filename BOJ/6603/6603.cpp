#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 15

int k;
int arr[MAX];
bool isUsed[MAX];

void func(vector<int> v, int num, int cnt)
{
	if (cnt == 6)
	{
		sort(arr, arr + 6);
		for (int i = 0; i < 6; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = num; i <= k; i++)
	{
		if (isUsed[i]) continue;
		arr[cnt] = v[i-1];
		isUsed[i] = true;
		func(v, i + 1, cnt + 1);
		isUsed[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while (true)
	{
		cin >> k;
		if (k == 0) break;
		vector<int> vec;

		for (int i = 0; i < k; i++)
		{
			int num;
			cin >> num;
			vec.push_back(num);
		}
		sort(vec.begin(), vec.end());
		func(vec, 1, 0);
		cout << '\n';
		memset(arr, 0, sizeof(arr));
		memset(isUsed, 0, sizeof(isUsed));
		vec.clear();
	}

	return 0;
}