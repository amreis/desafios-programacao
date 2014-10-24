#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> adjlist;

int main()
{
    int n, r;
    int nCase = 1;
    bool first = true;
    adjlist graph;
    while (cin >> n >> r && ! (n == 0 && r == 0))
    {
        if (!first) cout << endl;
        int matrix[n][n];
        memset(matrix, -1, sizeof(matrix));
        for (int i = 0; i < r; ++i)
        {
            int c1, c2, p;
            cin >> c1 >> c2 >> p;
            c1--; c2--;
            p--; // The guide must go as well.
            matrix[c1][c2] = matrix[c2][c1] = p;
        }
        for (int k = 0; k < n; ++k)
            matrix[k][k] = 0;
        int s, t, q;
        cin >> s >> t >> q;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                {
                    // We are trying to get the path with the biggest minimum passenger capacity
                    // possible, so we can make as few trips as possible.
                    // So, we take the smallest weight between the paths (i...k) and (k...j)
                    // and compare it to what we've got. If what we've got is bigger, we don't change it.
                    matrix[i][j] = max(matrix[i][j], min(matrix[i][k], matrix[k][j]));
                }
        cout << "Scenario #" << nCase++ << endl;
        cout << "Minimum Number of Trips = ";
        cout << int(ceil((float)q/matrix[s-1][t-1])) << endl;
        first = false;
    }
}
