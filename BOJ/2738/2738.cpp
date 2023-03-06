#include <iostream>
using namespace std;
#define MAX 100
int n, m;
int proc1[MAX][MAX];
int proc2[MAX][MAX];
int sum[MAX][MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> proc1[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> proc2[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << proc1[i][j] + proc2[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}