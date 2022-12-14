#include <iostream>
#include <vector>

using namespace std;

int N, weight, height;
vector<pair<int, int>> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> weight >> height;
		v.push_back({ weight, height });
	}

	for (int i = 0; i < N; i++)
	{
		int rank = 1;
		for (int j = 0; j < N; j++)
		{
			if (v[i].first < v[j].first && v[i].second < v[j].second)
			{
				rank++;
			}
		}
		cout << rank << " ";
	}

	return 0;
}