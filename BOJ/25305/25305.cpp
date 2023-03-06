#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    int scores[1000] = { 0, };

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }
    sort(scores, scores + n);
    cout << scores[n - k];
    return 0;
}