#include <iostream>

using namespace std;

int main()
{
    int n, temp;
    cin >> n;
    int arr[1000];

    // 배열 입력
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 앞에 있는 수보다 뒤에 있는 수가 작으면 위치 바꿔줌
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}