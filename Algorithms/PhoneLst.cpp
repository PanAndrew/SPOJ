//Login: Nukat
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t, n;
	bool flag;
	vector<string> vec;
	string numbers;

	cin >> t;

	while (t--)
	{
		cin >> n;

		for (int i = 0; i<n; i++)
		{
			cin >> numbers;
			vec.push_back(numbers);
		}

		if (vec.size() == 1)
		{
			cout << "YES" << endl;
			vec.clear();
			continue;
		}

		sort(vec.begin(), vec.end());

		string prev_to_cmp = vec.front();
		flag = false;

		for (int i = 1; i<vec.size() && !flag; i++)
		{
			int len = prev_to_cmp.length();
			string temp_to_cmp = vec.at(i).substr(0, len);
			
			if (temp_to_cmp == prev_to_cmp)
			{
				cout << "NO" << endl;
				flag = true;
				break;
			}

			prev_to_cmp = vec.at(i);
		}

		if (!flag)
		{
			cout << "YES" << endl;
		}

		vec.clear();
	}
}