#include <iostream>
#include <algorithm>
using namespace std;

int n;
int scores[1001];

float newAvg(float score)
{
    float sum = 0;
    float avg = 0;
    for (int i = 0; i < n; i++)
    {
        float newScore = scores[i] / score * 100;
        sum += newScore;
    }
    
    avg = sum / n;
    return avg;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }

    sort(scores, scores + n);

    float highScore = scores[n - 1];
    float ans = newAvg(highScore);

    cout << ans;
    
    return 0;
}