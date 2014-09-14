#include <iostream>

#include <vector>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

class PosColorDir
{
private:
    pair<ii,ii> ijcd;
public:
    pair<ii,ii> getCoords() const
    { return this->ijcd; }
    PosColorDir()
    {
        ijcd = make_pair(ii(0,0), ii(0,0));
    }
    PosColorDir(int i, int j, int c, int d)
    {
        ijcd = make_pair(ii(i,j), ii(c,d));
    }
    PosColorDir(const PosColorDir& other)
    {
        this->ijcd = other.getCoords();
    }
    bool operator<(PosColorDir o) const
    {
        return ijcd < o.getCoords();
    }
    bool operator==(PosColorDir o) const
    {
        int i = getI(), j = getJ(), c = getC();
        return i == o.getI() && j == o.getJ() && c == o.getC();
    }
    void setCoords(int i, int j, int c, int d)
    {
        this->ijcd = make_pair(ii(i,j), ii(c,d));
    }
    
    bool isInsideGrid(int M, int N)
    {
        int i = this->ijcd.first.first, j = this->ijcd.first.second;
        if (i < 0 || j < 0 || i>= M || j >= N)
            return false;
        return true;
    }
    
    int getI() const
    {
        return this->ijcd.first.first;
    }
    int getJ() const
    {
        return this->ijcd.first.second;
    }
    int getC() const
    {
        return this->ijcd.second.first;
    }
    int getD() const
    {
        return this->ijcd.second.second;
    }
    
};

int main()
{
    int M, N;
    int test = 0;
    while (cin >> M >> N && !(M == 0 && N == 0))
    {
        ++test;
        if (test != 1)
            cout << endl;
        bool visited[M][N][5][4];
        memset(visited, false, sizeof(visited));
        bool free[M][N];
        memset(free, true, sizeof(free));
        PosColorDir s, t;
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                char c;
                cin >> c;
                switch(c)
                {
                case '#':
                    free[i][j] = false;
                    break;
                case 'S':
                    s.setCoords(i,j,0,0);
                    break;
                case 'T':
                    t.setCoords(i,j,0,0);
                    break;
                default:
                    break;
                }
            }
        }
        
        queue<PosColorDir> q;
        map<PosColorDir, int> costs;
        costs[s] = 0;
        q.push(s);
        int minCost = 0;
        while (!q.empty())
        {
            PosColorDir x = q.front(); q.pop();
            pair<ii,ii> h = x.getCoords();
            int i = h.first.first, j = h.first.second, c = h.second.first, d = h.second.second;
            if (x == t)
            {
                minCost = costs[x];
                break;
            }
            if (visited[i][j][c][d]) continue;
            // Go Forward
            PosColorDir next(x);
            int nextC = (c+1) %5;
            switch(d)
            {
            case 0:
                next.setCoords(i-1, j, nextC, d);
                break;
            case 1:
                next.setCoords(i, j+1, nextC, d);
                break;
            case 2:
                next.setCoords(i+1, j, nextC, d);
                break;
            case 3:
                next.setCoords(i, j-1, nextC, d);
                break;
            }
            if (next.isInsideGrid(M, N) && free[next.getI()][next.getJ()] && ! visited[next.getI()][next.getJ()][next.getC()][next.getD()])
            {
                costs[next] = costs[x] + 1;
                q.push(next);
            }
            int newD;
            newD = (d+1) % 4;
            next.setCoords(i,j,c,newD);
            if (!visited[next.getI()][next.getJ()][next.getC()][next.getD()])
            {
                costs[next] = costs[x] + 1;
                q.push(next);
            }
            
            newD = ((d-1 >= 0) ? d-1 : d + 3);
            next.setCoords(i,j,c,newD);
            if (!visited[next.getI()][next.getJ()][next.getC()][next.getD()])
            {
                costs[next] = costs[x] + 1;
                q.push(next);
            }
            
            visited[i][j][c][d] = true;
        }
        cout << "Case #" << test << endl;
        if (minCost > 0)
            cout << "minimum time = " << minCost << " sec" << endl;
        else
            cout << "destination not reachable" << endl;
    }
    
    
    return 0;
}
