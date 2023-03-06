#include <iostream>
#include <algorithm>

using namespace std;

int arr[9] { 0, };

void solve()
{
    int max = 0;
    int num = 0;

    for (int i = 0; i < 9; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            num = i + 1;
        }
    }

    cout << max << '\n' << num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }

    solve();

    return 0;
}
