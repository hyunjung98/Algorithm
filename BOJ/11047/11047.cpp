#include <iostream>
using namespace std;

int n, k;
int arr[10];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;

    for (int i = n-1; i >= 0; i--)
    {
        ans += k / arr[i];
        k %= arr[i];
    }
    cout << ans;
    return 0;
}