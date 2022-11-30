#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x, y;

    cin >> n;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({ x, y });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }

}