// Login: Nukat
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64_t mod = 1000000007;
	int n, m;
	int64_t result = 1;

	cin >> n >> m;

	cin.ignore();

	vector<set<char>> letters;
	
	for (int i = 0; i < m; i++)
	{
		set<char> init;
		letters.push_back(init);
	}

	string word;
	
	for (int i = 0; i < n; i++)
	{
		getline(std::cin, word);
		
		for (int j = 0; j < m; j++)
		{
			letters.at(j).insert(word.at(j));
		}
	}

	for (int i = 0; i < m; i++)
	{
		result *= letters.at(i).size();
		result %= mod;
	}

	cout << result;

    return 0;
}