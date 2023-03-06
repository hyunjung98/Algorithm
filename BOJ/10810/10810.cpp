#include <iostream>
using namespace std;

int n, m;
int arr[101] = { 0, };

void solve(int start, int end, int num)
{
    for (int i = start; i <= end; i++)
    {
        arr[i] = num;
    }
}

void p()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int first, last, ballNum;
        cin >> first >> last >> ballNum;
        solve(first-1, last-1, ballNum);
    }

    p();
    return 0;
}