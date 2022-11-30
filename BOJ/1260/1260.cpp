#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 1001

int N, M, V;            // N: 정점, M: 간선, V: 시작 정점 번호
vector<int> vec[MAX];   // 인접 리스트
bool visited[MAX];      // 정점 방문 체크
queue<int> q;
stack<int> s;

// 재귀 함수 사용
void DFS_Recursion(int v)
{
    visited[v] = true;
    cout << v << " ";

    // vec[v]와 연결된 수만큼 반복
    for (int i = 0; i < vec[v].size(); i++)
    {
        int next = vec[v][i];
        if (visited[next] == false)
        {
            DFS_Recursion(next);
        }
    }
}

// 스택 사용
void DFS(int v)
{
    s.push(v);

    while (!s.empty())
    {
        // 가장 위에 있는 요소 저장하고 빼기
        v = s.top();
        s.pop();

        if (visited[v]) continue;
        visited[v] = true;
        cout << v << " ";

        // vec[v]와 연결된 수만큼 반복
        for (int i = 0; i < vec[v].size(); i++)
        {
            // 스택의 선입후출 특징 때문에 역순으로 넣어주기 
            int next = vec[v][vec[v].size() - 1 - i];
            if (visited[next] == false)
            {
                if (visited[next]) continue;
                s.push(next);
            }
        }

    }
}

void BFS(int v)
{
    // 현재 정점을 큐에 넣고 방문처리
    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        // 가장 앞에 있는 요소 저장하고 빼기
        v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < vec[v].size(); i++)
        {
            int next = vec[v][i];
            if (visited[next] == false)
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

// 방문 처리 초기화 함수
void ResetVisited()
{
    for (int i = 1; i <= N; i++)
        visited[i] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        vec[from].push_back(to);
        vec[to].push_back(from);
    }

    // 오름차순 정렬 - 작은 숫자부터 방문해야 하기 때문이다
    for (int i = 1; i <= N; i++)
        sort(vec[i].begin(), vec[i].end());

    ResetVisited();
    DFS(V);

    cout << '\n';

    ResetVisited();
    BFS(V);
}
