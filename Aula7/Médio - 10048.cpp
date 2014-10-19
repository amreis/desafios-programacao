#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> adjlist;
typedef priority_queue<ii, vector<ii>, greater<ii> > rev_queue;

adjlist graph;

int maxDecibels(int a, int b)
{
    vector<int> cost(graph.size(), -1);
    rev_queue q;
    q.push(ii(0, a));
    while (!q.empty())
    {
        ii x = q.top(); q.pop();
        if (x.second == b)
        {
            return x.first;
        }
        else if (cost[x.second] != -1)
            continue;
        else
        {
            for (size_t i = 0; i < graph[x.second].size();++i)
            {
                ii y = graph[x.second][i];
                q.push(ii(max(y.first, x.first), y.second));
            }
        }
        cost[x.second] = x.first;
    }
    return -1;
}


int main()
{
    int c, s, q;
    int nCase = 1;
    bool first = true;
    while (cin >> c >> s >> q)
    {
        if (c == 0 && s == 0 && q == 0) break;
        if (!first) cout << endl;
        cout << "Case #" << nCase << endl;
        graph.assign(c, vii());
        for (int _s = 0; _s < s; ++_s)
        {
            int c1, c2, d;
            cin >> c1 >> c2 >> d;
            c1--; c2--;
            graph[c1].push_back(ii(d, c2));
            graph[c2].push_back(ii(d, c1));
        }
        for (int _q = 0; _q < q; ++_q)
        {
            int c1, c2;
            cin >> c1 >> c2;
            c1--; c2--;
            int d = maxDecibels(c1,c2);
            if (d == -1)
                cout << "no path" << endl;
            else cout << d << endl;
        }
        nCase++;
        first = false;
    }
    return 0;
}
