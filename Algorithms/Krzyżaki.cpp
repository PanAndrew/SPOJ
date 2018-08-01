//Login: Nukat
#include <iostream>

using namespace std;

int main()
{
	int64_t n;

	int64_t point[3];
	int64_t point2[3];
	int64_t point3[3];
	int64_t vector1[3];
	int64_t vector2[3];
	int64_t normalna[3];

	cin >> n;

	if (n <= 3)
	{
		cout << "TAK" << "\n";
	}
	else
	{
		//Wczytanie punktow
		cin >> point[0] >> point[1] >> point[2];
		cin >> point2[0] >> point2[1] >> point2[2];
		n -= 2;

		do
		{
			if (n == 0)
			{
				cout << "TAK" << "\n";
				return 0;
			}

			cin >> point3[0] >> point3[1] >> point3[2];
			n--;
			//Obliczenie wektorow
			vector1[0] = point2[0] - point[0];
			vector1[1] = point2[1] - point[1];
			vector1[2] = point2[2] - point[2];

			vector2[0] = point3[0] - point[0];
			vector2[1] = point3[1] - point[1];
			vector2[2] = point3[2] - point[2];

			//Wyznaczenie wektora prostopadlego
			normalna[0] = (vector2[1] * vector1[2]) - (vector2[2] * vector1[1]);
			normalna[1] = (-1 * ((vector2[0] * vector1[2]) - (vector2[2] * vector1[0])));
			normalna[2] = (vector2[0] * vector1[1]) - (vector2[1] * vector1[0]);

		} while (normalna[0] == 0 && normalna[1] == 0 && normalna[2] == 0);

		//Sprawdzanie czy kolejne punkty sa rownolegle do plaszczyzny
		if (n > 0)
		{
			while(n)
			{
				cin >> point2[0] >> point2[1] >> point2[2];

				vector1[0] = point2[0] - point[0];
				vector1[1] = point2[1] - point[1];
				vector1[2] = point2[2] - point[2];

				vector2[0] = normalna[0] * vector1[0];
				vector2[1] = normalna[1] * vector1[1];
				vector2[2] = normalna[2] * vector1[2];

				if (vector2[0] + vector2[1] + vector2[2] != 0)
				{
					cout << "NIE" << "\n";
					break;
				}

				n--;

				if (n == 0)
					cout << "TAK" << "\n";
			}
		}
		else
			cout << "TAK" << "\n";
	}

    return 0;
}

