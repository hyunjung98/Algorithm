#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 15

int L, C;
char arr[MAX];
bool isUsed[MAX];
vector<char> vCode;

bool CheckCode()
{
    int consonantCount = 0;
    int vowelCount = 0;

    for (int i = 0; i < L; i++)
    {
        if (vCode[i] == 'a' || vCode[i] == 'e' ||
            vCode[i] == 'i' || vCode[i] == 'o' ||
            vCode[i] == 'u')
            vowelCount++;
        else
            consonantCount++;
    }
    if (vowelCount >= 1 && consonantCount >= 2)
    {
        return true;
    }

    return false;
}

void Dfs(int num)
{
    if ((int)vCode.size() == L && CheckCode())
    {
        for (int i = 0; i < L; i++)
        {
            cout << vCode[i];
        }
        cout << '\n';
        return;
    }

    for (int i = num; i < C; i++)
    {
        if (isUsed[i]) continue;
        vCode.push_back(arr[i]);
        isUsed[i] = true;
        Dfs(i + 1);
        vCode.pop_back();
        isUsed[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + C);
    Dfs(0);

    return 0;
}