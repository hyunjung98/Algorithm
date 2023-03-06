#include <iostream>
using namespace std;

int n, v;
int arr[101];

int solve(int num)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (num == arr[i])
            cnt++;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> v;
    int ans = solve(v);
    cout << ans;

    return 0;
}