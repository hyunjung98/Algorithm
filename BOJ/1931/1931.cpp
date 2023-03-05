#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> pTime[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pTime[i].second >> pTime[i].first;
	}

	sort(pTime, pTime + n);		// 끝나는 시간 기준 오름차순 정렬
	
	int ans = 0;
	int t = 0;

	for (int i = 0; i < n; i++)
	{
		if (t > pTime[i].second) continue;
			t = pTime[i].first;
			ans++;
	}
	cout << ans;

	return 0;
}