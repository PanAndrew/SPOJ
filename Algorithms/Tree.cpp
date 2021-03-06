//Login: Nukat
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[10001];
int result;

int DFS(vector<int> vec_graph[], int beg)
{
	int path1 = 0, path2 = 0;
	int temp = 0;

	visited[beg] = 1;

	for (int i = 0; i < vec_graph[beg].size(); i++)
	{
		if (!(visited[vec_graph[beg][i]]))
		{
			temp = DFS(vec_graph, vec_graph[beg][i]);

			if (temp >= path1)
			{
				path2 = path1;
				path1 = temp;
			}
			else if (temp > path2)
				path2 = temp;
		}
	}

	result = max(result, path1 + path2);
	return path1 + 1;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n_of_nodes, u, v;
	cin >> n_of_nodes;

	vector<int>* vec_graph = new vector<int>[n_of_nodes + 1];

	for (int i = 0; i < n_of_nodes - 1; i++)
	{
		cin >> u >> v;
		vec_graph[u].push_back(v);
		vec_graph[v].push_back(u);
	}

	DFS(vec_graph, 1);

	cout << result << "\n";

	return 0;
}