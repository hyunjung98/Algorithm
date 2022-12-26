#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000001

int n, k;
int dis[MAX];
queue<int> q;

int Bfs(int start, int finish)
{
    q.push(n);
    while (!q.empty())
    {
        int cur = q.front();
        int dir[3] = { 1, -1, cur };    // 수빈이가 이동할 수 있는 방향 벡터
        q.pop();

        // 현재 위치가 동생의 위치라면 이동 횟수 반환
        if (cur == finish) return dis[cur];

        for (int i = 0; i < 3; i++)
        {
            int next = cur + dir[i];
            if (next < 0 || next >= MAX || dis[next] != 0) continue;
            q.push(next);
            dis[next] = dis[cur] + 1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    int result = Bfs(n, k);
    cout << result;

    return 0;
}
