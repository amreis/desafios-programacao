#include <iostream>

#include <set>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> adjList;

class UnionFind
{
private:
    vector<int> p;
    vector<int> s;
    vector<int> r;
    int count;
public:
    UnionFind() { p.clear(), s.clear(), count = 0; }
    void MakeSets(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            p.push_back(i);
            s.push_back(1);
            r.push_back(0);
            count++;
        }
    }
    
    int Find(int x)
    {
        if (p[x] != x)
            p[x] = Find(p[x]);
        return p[x];
    }
    
    void Union(int x, int y)
    {
        int xRoot = Find(x), yRoot = Find(y);
        if (xRoot == yRoot)
            return;
        if (r[xRoot] < r[yRoot])
        {
            p[xRoot] = yRoot;
            s[yRoot] += s[xRoot];
        }
        else if (r[xRoot] > r[yRoot])
        {
            p[yRoot] = xRoot;
            s[xRoot] += s[yRoot];
        }
        else
        {
            p[yRoot] = xRoot;
            r[xRoot] += 1;
            s[xRoot] += s[yRoot];
        }
        count --;
    }
    
    bool Connected(int x, int y)
    { return Find(x) == Find(y); }
    
    int getCount() const
    { return count; }
};

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n, m, a;
        cin >> n >> m >> a;
        adjList graph;
        graph.assign(n, vii());
        UnionFind uf;
        uf.MakeSets(n);
        priority_queue< pair<int, ii>, vector<pair<int,ii>>, greater<pair<int,ii>>> q;
        for (int i = 0; i < m; ++i)
        {
            int x, y, c;
            cin >> x >> y >> c;
            q.push(make_pair(c, ii(x-1,y-1)));
            q.push(make_pair(c, ii(y-1,x-1)));
        }
        int total = 0;
        int nAirports = 0;
        while (! q.empty() )
        {
            pair<int, ii> k = q.top(); q.pop();
            int c = k.first, x = k.second.first, y = k.second.second;
            if (! uf.Connected(x,y) )
            {
                uf.Union(x,y);
                if (c >= a)
                {
                    total += a;
                    nAirports ++;
                    q.push(k);
                }
                else
                    total += c;
            }
        }
        nAirports += uf.getCount();
        total += uf.getCount()*a;
        cout << "Case #" << t << ": " << total << " " << nAirports << endl;
    }
}
