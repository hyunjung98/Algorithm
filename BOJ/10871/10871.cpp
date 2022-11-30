#include <iostream>

using namespace std;

int main()
{
    int n;
    int x;

    cin >> n >> x;

    int sequence[10000] = {};

    for (int i = 0; i < n; i++)
    {
        cin >> sequence[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (sequence[i] < x)
        {
            cout << sequence[i] << " ";
        }
    }
}