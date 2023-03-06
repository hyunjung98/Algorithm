#include <iostream>
#include <algorithm>
using namespace std;
int arr[5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    int avg = sum / 5;
    sort(arr, arr + 5);
    int mid = arr[2];

    cout << avg << '\n' << mid;

    return 0;
}
