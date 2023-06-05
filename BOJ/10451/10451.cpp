#include <iostream>
#include <vector>
#include <cstring>

#define MAX 1001

using namespace std;

vector<int> vec[MAX];
bool visited[MAX];

void dfs(int v)
{
    visited[v] = true;
    for (int i = 0; i < vec[v].size(); i++)
    {
        int next = vec[v][i];
        if (!visited[next]) dfs(next);
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;
    while (true)
    {
        if (tc == 0) break;
        int size;
        cin >> size;
        int cnt = 0;
        for (int i = 1; i <= size; i++)
        {
            int n;
            cin >> n;
            vec[i].push_back(n);
            vec[n].push_back(i);
        }

        for (int i = 1; i <= size; i++)
        {
            if (!visited[i])
            {
                dfs(i);
                cnt++;
            }
        }

        cout << cnt << '\n';
        memset(vec, 0, sizeof(vec));
        memset(visited, 0, sizeof(visited));
        tc--;
    }
    return 0;
}