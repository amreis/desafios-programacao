#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> adjlist;
typedef priority_queue< ii, vector<ii>, greater<ii> > rev_queue;



int dijkstra(int a, int b, const adjlist& graph)
{
	rev_queue q;
	q.push( ii(0, a) );
	if (graph.size() <= 1) return -1;
	vector<bool> visited(graph.size(), false);
	vector<int> costs(graph.size(), INT_MAX);
	costs[a] = 0;
	while (! q.empty() )
	{
		ii x = q.top(); q.pop();
		if (visited[x.second])
			continue;
		if (x.second == b)
			return x.first;
		for (int i = 0; i < graph[x.second].size(); ++i)
		{
			ii y = graph[x.second][i];
			if (costs[y.second] > costs[x.second] + y.first)
			{
				costs[y.second] = costs[x.second] + y.first;
				q.push(ii(costs[x.second] + y.first, y.second));
			}
		}
		visited[x.second] = true;
	}
	return -1;
}


int main()
{
	int N_TESTS;
	cin >> N_TESTS;
	for (int testNumber = 1; testNumber <= N_TESTS; ++testNumber)
	{
		int n, m, s, t;
		cin >> n >> m >> s >> t;
		adjlist graph;
		graph.assign(n, vii());
		for (int i = 0; i < m; ++i)
		{
			int a, b, w;
			cin >> a >> b >> w;
			graph[a].push_back( ii(w, b) );
			graph[b].push_back( ii(w, a) );
		}
		int dist = dijkstra(s, t, graph);
		cout << "Case #" << testNumber << ": ";
		if (dist != -1)
			cout << dist << endl;
		else
			cout << "unreachable" << endl;
	}
}
