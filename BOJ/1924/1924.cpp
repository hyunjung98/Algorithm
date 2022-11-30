#include <iostream>

using namespace std;

int main()
{
    int month;
    int day;

    int daysOfMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    string days[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

    cin >> month >> day;

    for (int i = 1; i < month; i++)
    {
        day += daysOfMonth[i];
    }
    cout << days[day % 7];
}