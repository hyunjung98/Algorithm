#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    else if (p1.second == p2.second)
    {
        if (p1.first < p2.first)
            return true;
    }
    return false;
}

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

    sort(v.begin(), v.end(), Comp);

    for (int i = 0; i < n; i++)
    {

        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}