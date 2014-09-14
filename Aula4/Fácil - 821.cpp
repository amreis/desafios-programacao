#include <iostream>
#include <queue>
#include <climits>
#include <iomanip>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> adjlist;
typedef priority_queue< ii, vector<ii>, greater<ii> > rev_queue;


vector<int> dijkstra(int a, const adjlist& graph)
{
	vector<int> visited(graph.size(), -1);
	rev_queue q;
	q.push( ii(0, a) );
	vector<int> cost(graph.size(), INT_MAX);
	cost[a] = 0;

	if (graph[a].empty()) return vector<int>();
	while (! q.empty() )
	{
		ii x = q.top(); q.pop();
		if (visited[x.second] != -1)
			continue;
		for (int i = 0; i < graph[x.second].size(); ++i)
		{
			ii y = graph[x.second][i];

			if (cost[y.first] > cost[x.second] + y.second)
			{
				cost[y.first] = cost[x.second] + y.second;

				q.push( ii( cost[y.first], y.first ) ); 
			}
		}
		visited[x.second] = 0;
	}
	return cost;
}

int main()
{
	int nCase = 1;
	while (true)
	{
		adjlist graph;
		int a, b;
		int nEdges = 0;
		int nNodes = -1;
		vii buff;
		while (cin >> a >> b)
		{
			if (a == 0 && b == 0)
				break;
			buff.push_back(ii(a,b));
			nEdges ++;
			nNodes = max(max(nNodes, a), b);
		}

		if (nEdges == 0) break;

		graph.assign(nNodes+1, vii());
		for (int i = 0; i < nEdges; ++i)
		{
			ii node = buff[i];
			graph[node.first].push_back(ii(node.second, 1));
		}
		double sum = 0;
		int nRealNodes = 0;
		for (int i = 1; i < graph.size(); ++i)
		{
			vector<int> distance = dijkstra(i, graph);
			if (!distance.empty()) nRealNodes++;
			for (size_t j = 1; j < distance.size(); ++j)
				if (distance[j] != INT_MAX) sum += distance[j];
		}
		
		sum /= (nRealNodes)*(nRealNodes-1);
		printf("Case %d: average length between pages = %.3lf clicks\n", nCase++, sum);

	}
}
