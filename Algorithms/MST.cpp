//Login: Nukat
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int n_of_nodes = 10001;
typedef pair<long long, int> PWN;
bool marked[n_of_nodes];
vector <PWN> unadded[n_of_nodes];

long long prim_alg(int x)
{
	priority_queue<PWN, vector<PWN>, greater<PWN> > Que;
	PWN p;
	int temp;
	long long minCost = 0;
	Que.push(make_pair(0, x));

	while (!Que.empty())
	{
		p = Que.top();
		Que.pop();
		x = p.second;

		if (marked[x] == true)
			continue;

		minCost += p.first;
		marked[x] = true;

		for (int i = 0; i < unadded[x].size(); ++i)
		{
			temp = unadded[x][i].second;
			if (marked[temp] == false)
				Que.push(unadded[x][i]);
		}
	}
	return minCost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int nodes, edges, x, y;
	long long weight, result;

	cin >> nodes >> edges;

	for (int i = 0; i < edges; ++i)
	{
		cin >> x >> y >> weight;
		unadded[x].push_back(make_pair(weight, y));
		unadded[y].push_back(make_pair(weight, x));
	}

	result = prim_alg(1);
	cout << result << "\n";
	return 0;
}
