//Login:Nukat
#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	for(int i = 0; i<n; i++)
	{
		double a, b, p, q;

		cin >> a >> b >> p >> q;

		if (a < b)
		{
			int temp;
			temp = a;
			a = b;
			b = temp;
		}

		if (p < q)
		{
			int temp;
			temp = p;
			p = q;
			q = temp;
		}

		if (p < a && q < b)
			cout << "TAK" << endl;
		else if (p > a && q < b && ((a + b) / (p + q)) * ((a + b) / (p + q)) + ((a - b) / (p - q)) * ((a - b) / (p - q)) > 2)
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;
	}

    return 0;
}