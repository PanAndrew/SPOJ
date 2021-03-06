//Login: Nukat
#include <iostream>
#include <vector>
#include <queue>
#include "string.h"

using namespace std;

int BFS(vector<int> vec_graph[], int n_of_bugs)
{
	bool visited[n_of_bugs + 1];
	int gender[n_of_bugs + 1];

	bool flag = false;
	int node;

	memset(visited, 0, sizeof(visited));
	memset(gender, -1, sizeof(gender));

	for (int j = 1; j <= n_of_bugs; j++)
	{

		if (!(visited[j]))
		{
			queue<int> q;
			q.push(j);
			gender[j] = 1;

			while (!(q.empty()))
			{
				node = q.front();
				q.pop();
				visited[node] = 1;

				for (int i = 0; i < vec_graph[node].size(); i++)
				{

					if (gender[vec_graph[node][i]] == -1)
						gender[vec_graph[node][i]] = !gender[node];

					else if (gender[vec_graph[node][i]] == gender[node])
					{
						flag = true;
						break;
					}

					if (!(visited[vec_graph[node][i]]))
						q.push(vec_graph[node][i]);
				}

				if (flag)
					break;
			}
		}

		if (flag)
			break;
	}

	return flag;
}


int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases, n_of_bugs, n_of_interactions, u, v;
	int counter = 1;

	cin >> cases;

	while (cases--)
	{
		cin >> n_of_bugs >> n_of_interactions;

		vector<int>* vec_graph = new vector<int>[n_of_bugs + 1];

		for (int i = 0; i < n_of_interactions; i++)
		{
			cin >> u >> v;
			vec_graph[u].push_back(v);
			vec_graph[v].push_back(u);
		}

		cout << "Scenario #" << counter << ":\n";

		if (BFS(vec_graph, n_of_bugs))
			cout << "Suspicious bugs found!\n";
		else
			cout << "No suspicious bugs found!\n";

		counter++;
	}

	return 0;
}
