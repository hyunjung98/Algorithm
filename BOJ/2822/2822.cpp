#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int score;
    int sum = 0;
    vector<pair<int, int>> v;
    vector<int> idx;

    for (int i = 0; i < 8; i++)
    {
        cin >> score;
        v.push_back({ score, i + 1 });
    }

    sort(v.begin(), v.end(), greater<pair<int, int>>());

    for (int i = 0; i < 5; i++)
    {
        sum += v[i].first;
        idx.push_back(v[i].second);
    }

    cout << sum << '\n';

    sort(idx.begin(), idx.end());

    for (int i = 0; i < 5; i++)
    {
        cout << idx[i] << ' ';
    }
}
