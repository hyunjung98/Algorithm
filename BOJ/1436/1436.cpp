#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int title = 665;
	int cnt = 0;

	string str;

	while (title++)
	{
		str = to_string(title);
		if (str.find("666") != string::npos)
			cnt++;
		if (cnt == n) break;
	}

	cout << title;

	return 0;
}