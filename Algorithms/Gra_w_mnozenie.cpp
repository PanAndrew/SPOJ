#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	uint64_t n, p = 1;

	while (cin >> n)
	{
		while (1)
		{
			p *= 9;
			if (p >= n)
			{
				cout << "A\n";
				p = 1;
				break;
			}

			p *= 2;
			if (p >= n)
			{
				cout << "B\n";
				p = 1;
				break;
			}
		}
	}

	return 0;
}