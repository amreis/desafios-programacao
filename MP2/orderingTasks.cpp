#include <iostream>

#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vii;
typedef vector<vii> adjlist;


adjlist graph;
vector<int> toposorted;
vector<bool> visited;
void toposort()
{
	vector<int> inDegrees(graph.size(), 0);
	for (size_t i = 0; i < graph.size(); ++i)
	{
		for (size_t j = 0; j < graph[i].size(); ++j)
		{
			inDegrees[graph[i][j]]++;	
		}
	}
	for (size_t i = 0; i < inDegrees.size(); ++i)
	{
		for (size_t j = 0; j < inDegrees.size(); ++j)
		{
			if (inDegrees[j] == 0)
			{
				for (size_t k = 0; k < graph[j].size(); ++k)
				{
					inDegrees[graph[j][k]]--;
				}
				inDegrees[j] = -1;
				toposorted.push_back(j+1);
			}
		}
	}
}

ostream& operator<<(ostream& os, const vector<int>& v)
{
	if (v.empty()) return os;
	for (size_t i = 0; i < v.size()-1; ++i)
	{
		os << v[i] << " " ;
	}
	os << v[v.size()-1];
	return os;
}


int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		graph.assign(n, vii());
		toposorted.clear();
		visited.assign(n, 0);
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			cin >> u >> v;
			u--; v--;
			graph[u].push_back(v);
		}
		toposort();
		cout << toposorted << endl;
	}
	return 0;
}
