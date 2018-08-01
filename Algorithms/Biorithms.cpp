//Login: Nukat
#include <iostream>

using namespace std;

int countDays(int x, int mod)
{
	int aa = 1, ab = 0, ca = 0, cb = 1;
	int temp, srcMod = mod;
	int state;

	for (int i = 0; x%mod != 0; i = !i)
	{

		if (i == 0)
		{
			aa -= x / mod*ca;
			ab -= x / mod*cb;
		}
		else
		{
			ca -= x / mod*aa;
			cb -= x / mod*ab;
		}

		temp = x;
		x = mod;
		mod = temp%mod;
		state = !i;
	}

	if (state)
		return (aa%srcMod + srcMod) % srcMod;
	else
		return (ca%srcMod + srcMod) % srcMod;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int caseNumber=1, phis, emot, intel, days;
	int daysToTri;

	while (1)
	{
		cin >> phis >> emot >> intel >> days;

		if (phis == -1)
			break;

		daysToTri = phis * countDays(28 * 33, 23) * 28 * 33 + emot * countDays(23 * 33, 28) * 23 * 33 + intel * countDays(23 * 28, 33) * 23 * 28 - days;
		daysToTri += 21251;
		daysToTri %= 21252;
		daysToTri += 1;

		cout << "Case " << caseNumber << ": " << "the next triple peak occurs in " << daysToTri << " days.\n";
		caseNumber++;
	}

    return 0;
}
