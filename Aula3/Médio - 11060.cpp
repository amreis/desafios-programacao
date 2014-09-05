#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> adjList;

map<string, int> beverages;
map<int, string> bevFromInt;
adjList graph;
vi topsorted;

void toposort()
{
	vi indegrees(graph.size(), 0);
	topsorted.clear();
	for (size_t i = 0; i < graph.size(); ++i)
	{
		for (size_t j = 0; j < graph[i].size(); ++j)
		{
			int elem = graph[i][j];
			indegrees[elem]++;
		}
	}

	for (size_t i = 0; i < indegrees.size(); ++i)
	{
		bool found = false;
		for (size_t j = 0; j < indegrees.size(); ++j)
		{
			if (indegrees[j] == 0)
			{
				topsorted.push_back(j);
				indegrees[j] = -1;
				for (size_t k = 0; k < graph[j].size(); ++k)
					indegrees[graph[j][k]]--;
				found = true;
				break;
			}
		}
		if (!found)
			break;
	}
}


int main()
{
	int C = 1;
	int N;
	while (cin >> N && ! cin.bad())
	{
		beverages.clear();
		bevFromInt.clear();
		for (int i = 0; i < N; ++i)
		{
			string s;
			cin >> s;
			beverages.insert(make_pair(s, i));
			bevFromInt.insert(make_pair(i, s));
		}
		int M;
		cin >> M;
		graph.clear();
		graph.assign(N, vi());
		for (int i = 0; i < M; ++i)
		{
			string bev1, bev2;
			cin >> bev1 >> bev2;
			graph[beverages.at(bev1)].push_back(beverages.at(bev2));
		}
		topsorted.clear();
		topsorted.assign(N, -1);
		toposort();
		cout << "Case #" << C << ": Dilbert should drink beverages in this\
 order: " ;
		for (int i = 0; i < topsorted.size() -1; ++i)
		{
			cout << bevFromInt[topsorted[i]] << " ";
		}
		cout << bevFromInt[topsorted[topsorted.size()-1]] << "."  << endl;
		cout << endl;
		
		C++;
	}
}
