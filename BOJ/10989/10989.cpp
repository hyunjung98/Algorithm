#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 10001


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    int arr[MAX] = { 0, };
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        arr[value]++;
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            cout << i << '\n';
        }
    }

    return 0;
}