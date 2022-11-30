#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Comp(pair<int, string> p1, pair<int, string> p2)
{
    return p1.first < p2.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int age;
    string name;
    cin >> n;

    vector<pair<int, string>> user;

    for (int i = 0; i < n; i++)
    {
        cin >> age >> name;
        user.push_back({ age, name });
    }

    stable_sort(user.begin(), user.end(), Comp);

    for (int i = 0; i < n; i++)
    {
        cout << user[i].first << ' ' << user[i].second << '\n';
    }
}