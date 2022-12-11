#include <iostream>

using namespace std;

#define MAX 101

int N, M;
int sum;
int result = 0;

int blackJack[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 카드의 개수와 딜러가 외친 숫자 입력 받기
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> blackJack[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				sum = blackJack[i] + blackJack[j] + blackJack[k];
				if (sum <= M)
				{
					result = max(result, sum);	// 둘 중 큰 값을 반환
				}
			}

		}
	}

	cout << result;
	return 0;
}