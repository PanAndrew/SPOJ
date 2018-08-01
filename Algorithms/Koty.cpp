#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, count = 0, dist;
	int wiek1, poz1, wiek2, poz2;

	cin >> n;
	while (count < n)
	{
		cin >> wiek1;
		cin >> poz1;
		cin >> wiek2;
		cin >> poz2;

		dist = abs(poz1 - poz2) + 1;

		if (wiek1 > wiek2)
		{
			if (dist % 3 == 2)
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << 1 << "\n";
			}
		}
		else
		{
			if (dist % 3 == 2)
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}

		count++;
	}


	return 0;
}