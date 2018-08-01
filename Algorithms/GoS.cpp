//Login: Nukat
#include <iostream>

using namespace std;

int main()
{
	int n, c;
	bool arrOfWins[1000001] = { false };
	int squares[1001];

	for (int i = 1; i < 1001; i++)
	{
		squares[i] = i*i;
	}

	for (int i = 1; i < 1000001; i++)
	{
		for (int j = 1; squares[j] <= i; j++)
		{
			arrOfWins[i] |= (!arrOfWins[i - squares[j]]);

			if (arrOfWins[i])
				break;
		}
	}

	cin >> n;

	while (n--)
	{
		cin >> c;

		if (arrOfWins[c] == true)
		{
			cout << "Win\n";
		}
		else
		{
			cout << "Lose\n";
		}
	}

    return 0;
}
