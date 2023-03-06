#include <iostream>
using namespace std;

int n;

int Fibonacci(int k)
{
    if (k == 0)
        return 0;
    else if (k == 1)
        return 1;
    else
        return Fibonacci(k-1) + Fibonacci(k - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int ans = Fibonacci(n);
    cout << ans;

    return 0;
}
