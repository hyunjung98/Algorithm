#include <iostream>
#include <set>
#include <vector>

using namespace std;

int cnt = 10;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int num = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        int element = num % 42;
        v.push_back(element);
    }
    
    set<int> s(v.begin(), v.end());

    cout << s.size();

    return 0;
}