#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> adjlist;
typedef priority_queue<ii, vii, greater<ii> > rev_queue;


int main()
{
	int nTests;
	cin >> nTests;
	for (int t = 1; t <= nTests; ++t)
	{
		adjlist graph;

		int n, m, a;
		cin >> n >> m >> a;
		graph.assign(n+1, vii());
		for (int i = 0; i < m; ++i)
		{
			int x, y, c;
			cin >> x >> y >> c;
			graph[x].push_back(make_pair(c, y));
			graph[y].push_back(make_pair(c, x));

		}
		vector<bool> visited(n+1, false);
		int cost = 0;
		int nAirplanes = 0;
		for (int i = 1; i <= n; ++i)
		{
			rev_queue q;
			if (visited[i]) continue;
			for (size_t j = 0; j < graph[i].size(); ++j)
			{
				if (!visited[graph[i][j].second] && !visited[i])
					q.push( graph[i][j] );
			}
			visited[i] = true;
			while (! q.empty() )
			{
				ii x = q.top(); q.pop();
				if (visited[x.second]) continue;
				if (x.first >= a)
				{
					visited[x.second] = true;
					break;
				}
				else {
					cost += x.first;
					for (size_t j = 0; j < graph[x.second].size(); ++j)
					{
						if (! visited[graph[x.second][j].second] )
							q.push( graph[x.second][j] );	
					}
				}
				visited[x.second] = true;
				
			}
			cost += a;
			nAirplanes++;
		}
		cout << "Case #" << t << ": " << cost << " " << nAirplanes << endl;
	}
}
