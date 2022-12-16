#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 51

int N, M;   // 세로, 가로
int board[MAX][MAX];
vector<int> v;

// 흰색 자리에 검은색이 존재할 경우 색칠해야하는 횟수를 증가
// 체스판이 검은색으로 시작했을 때 or 흰색으로 시작했을 때 색칠해야하는 수를 구하여 벡터에 저장
void CheckBoard(int n, int m)
{
	int _firstCount = 0;
	int _secondCount = 0;

	for (int i = n; i < n + 8; i++)
	{
		for (int j = m; j < m + 8; j++)
		{
			// 흰색 타일로 시작할 때
			if ((i + j) % 2 == board[i][j])
			{
				_firstCount++;
			}
			// 검정 타일로 시작할 때
			if ((i + j + 1) % 2 == board[i][j])
			{
				_secondCount++;
			}
		}
	}

	v.push_back(_firstCount);
	v.push_back(_secondCount);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 세로 가로 입력
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			// 검은색: 0, 하얀색 1로 변경하여 체스판 입력 받음
			if (str[j] == 'B')
				str[j] = 0;
			else
				str[j] = 1;
			board[i][j] = str[j];
		}
	}

	// 8*8 사이즈로 잘라 체스판 탐색
	for (int i = 0; i < N-7; i++)
	{
		for (int j = 0; j < M-7; j++)
		{
			CheckBoard(i, j);
		}
	}

	// 벡터에 담긴 수 중 가장 작은 값 반환하여 출력하기
	int answer = *min_element(v.begin(), v.end());
	cout << answer;

	return 0;
}