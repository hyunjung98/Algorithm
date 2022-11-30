#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int num;
	vector<int> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}
