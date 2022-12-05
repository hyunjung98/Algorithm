#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 100
#define _X first
#define _Y second

int board[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N;
int maxHeight = -1;     // 최대 높이 초기화

vector<int> vecArea;

void Dfs(int x, int y, int h)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (visited[nx][ny] || board[nx][ny] <= h) continue;
        visited[nx][ny] = true;
        Dfs(nx, ny, h);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 배열 입력
            cin >> board[i][j];
            
            // 최대 높이 저장
            if (maxHeight < board[i][j])
                maxHeight = board[i][j];
        }
    }

    int area = 0;
    int maxArea = 0;

    // 높이가 1부터 최대 높이의 횟수만큼 물에 잠기지 않는 구역을 탐색
    for (int h = 1; h <= maxHeight; h++)
    {
        // 방문 배열 초기화
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] > h && !visited[i][j])
                {
                    Dfs(i, j, h);
                    area++;
                }
            }
        }
        
        // 모든 높이에 대해 잠기지 않는 영역을 벡터에 저장
        vecArea.push_back(area);

        // 아무 지역도 물에 잠기지 않았을 경우 1로 세팅
        if (area == 0) vecArea.push_back(1);

        // 영역 초기화
        area = 0;
    }

    // 벡터 컨테이너의 최대값 구함
    int max = *max_element(vecArea.begin(), vecArea.end());
    cout << max;

    return 0;
}
