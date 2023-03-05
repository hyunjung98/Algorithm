#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100001];

void binarySearch(int k)
{
    int left = 0;
    int mid = 0;
    int right = n - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == k)
        {
            cout << 1 << '\n';
            return;
        }
        else if (arr[mid] > k)
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << 0 << '\n';
    return;
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
    sort(arr, arr + n);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        binarySearch(num);
    }
    
    return 0;
}