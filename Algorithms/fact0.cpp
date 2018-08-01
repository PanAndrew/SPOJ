//Login: Nukat
#include <iostream>
#include <vector>
 
using namespace std;
 
struct dzielnik
{
	uint64_t liczba;
	uint64_t ile;
 
	friend std::ostream& operator << (std::ostream& stream, const dzielnik& val)
	{
		stream << val.liczba << '^' << val.ile << ' ';
		return stream;
	}
};
 
inline void print(vector<dzielnik>& skladowe)
{										
	for (const auto& val : skladowe)	
	{									
		cout << val;					
	}									
										
	cout << "\n";						
	skladowe.clear();					
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	uint64_t n;
	vector<dzielnik> skladowe;
 
	while(true)
	{
		cin >> n;
 
		if (n == 0)
			return 0;
 
		if (n == 1)
		{
			cout << "1^1" << "\n";
			continue;
		}
 
		if (n % 2 == 0)
		{
			dzielnik dwa = { 2, 0 };
			do
			{
				n /= 2;
				dwa.ile++;
 
			} while (n % 2 == 0);
 
			skladowe.push_back(std::move(dwa));
		}
		
		if (n == 1)
		{
			print(skladowe);
			continue;
		}
 
		for (uint64_t i = 3; i * i <= n; i+=2)
		{
			if (n%i == 0)
			{
				skladowe.push_back(dzielnik{ i,0 });
				do
				{
					n /= i;
					skladowe.back().ile++;
					
				} while (n%i == 0);
			}
		}
 
		if (n != 1)
		{
			skladowe.push_back(dzielnik{ n,1 });
		}
 
		print(skladowe);
	}
 
	return 0;
} 