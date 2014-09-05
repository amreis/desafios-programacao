#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> adjList;

#define BLACK 1
#define WHITE 0
#define UNDEFINED -1

vi colors;
bool bicolorable = true;

void dfs(adjList &graph, int color, int start)
{
	if (colors[start] != UNDEFINED && colors[start] != color)
	{
		bicolorable = false;
		return;
	}
	else if (colors[start] != UNDEFINED)
		return;
	colors[start] = color;
	for (int i = 0; i < graph[start].size(); ++i)
	{
		dfs(graph, ((color == WHITE) ? BLACK : WHITE), graph[start][i]);
	}
}

int main()
{
	int nNodes, nEdges;
	while (cin >> nNodes && nNodes != 0)
	{
		cin >> nEdges;
		adjList graph(nNodes, vi());
		for (int i = 0; i < nEdges; ++i)
		{
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
			
		}
		colors.assign(nNodes, UNDEFINED);
		dfs(graph, WHITE, 0);
		if (bicolorable)
				cout << "BICOLORABLE." << endl;
			else
				cout << "NOT BICOLORABLE." << endl;
		bicolorable = true;
		
	}
	return 0;
}
