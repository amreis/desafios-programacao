#include <iostream>

#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;

typedef pair<double,int> di;
typedef pair<int, int> ii;
typedef vector<di> vdi;
typedef vector<vdi> adjlist;
typedef priority_queue< pair<double, ii>, vector< pair<double,ii> >, greater< pair<double,ii> > > rev_pq;


class UnionFind {
private:
	vector<int> p;
	vector<int> r;
	vector<int> s;
	int count;
	
public:
	void MakeSets(int size)
	{
		p.assign(size, 0);
		for (int i = 0; i < size; ++i)
		{
			p[i] = i;
		}
		
		r.assign(size, 1);
		s.assign(size, 1);
		count = size;
	}
	
	int Find(int x)
	{
		if (p[x] != x)
		{
			p[x] = Find(p[x]);
		}
		return p[x];
	}
	
	void Union(int x, int y)
	{
		int rootX = Find(x), rootY = Find(y);
		
		if (rootX == rootY)
			return;
			
		if (r[rootX] > r[rootY])
		{
			p[rootY] = rootX;
		} else if (r[rootY] > r[rootX])
		{
			p[rootX] = rootY;
		}
		else
		{
			p[rootX] = rootY;
			r[rootY]++;
		}
		
		count--;

	}
	
	bool Connected(int x, int y)
	{ return Find(x) == Find(y); }
	
	int Count()
	{ return count; }
};


vector<pair<double,double> > freckles;
int main()
{
	bool first = true;
	int N;
	cin >> N;
	for (int t = 0; t < N; ++t)
	{
		int nFreckles;
		cin >> nFreckles;
		if (!first) printf("\n");
		freckles.clear();
		for (int i = 0; i < nFreckles; ++i)
		{
			double x, y;
			cin >> x >> y;


			freckles.push_back(make_pair(x,y));
		}

		rev_pq q;
		for (int i = 0; i < nFreckles; ++i)
		{
			for (int j = i+1; j < nFreckles; ++j)
			{
				int x1, x2, y1, y2;
				x1 = freckles[i].first; y1 = freckles[i].second;
				x2 = freckles[j].first; y2 = freckles[j].second;
				double cost = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );

				q.push(make_pair(cost, make_pair(i,j))); q.push(make_pair(cost, make_pair(j,i)));
			}
		}
		UnionFind uf;
		uf.MakeSets(nFreckles);
		double cost = 0;
		while (!q.empty())
		{
			pair<double,ii> x = q.top(); q.pop();

			double w = x.first;
			int u = x.second.first;
			int v = x.second.second;
			
			if (uf.Connected(u,v))
				continue;
				
			uf.Union(u,v);
			cost += w;

		}
		first = false;
		printf("%.2lf\n", cost);
		
	}
}
