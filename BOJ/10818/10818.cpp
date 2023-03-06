#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000001] { 0, };

// sort 미사용
void solve()
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    cout << min << ' ' << max;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //solve();
    sort(arr, arr + n);
    cout << arr[0] << ' ' << arr[n - 1];

    return 0;
}