#include <iostream>
using namespace std;

int factorial(int k)
{
    if (k <= 1)
        return 1;
    else
        return k * factorial(k-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    int ans = factorial(n);
    cout << ans;

    return 0;
}