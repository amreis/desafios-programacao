#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int cuts[52] = {0};
int pd[52][52] = {0};
int main()
{
    int l;
    while (cin >> l && l != 0)
    {
        int n;
        cin >> n;

        for (int _n = 1; _n <= n; ++_n)
        {
            cin >> cuts[_n];
        }
        cuts[n+1] = l;
        // The idea here is to run through the diagonals, so we are always calculating
        // [i][i+k], for the kth diagonal.
        for (int step = 1; step <= n + 1; ++step)
        {
            // We must go through every row of the matrix where we can access the row + step column
            for (int row = 0; row + step <= n + 1; ++row)
            {
                // For the first diagonal, we can't make cuts, so cost zero.
                if (step == 1) pd[row][row+step] = 0;
                else
                {
                    int m = INT_MAX;
                    // Minimize cost of next cut location.
                    for (int k = row+1; k < row + step; ++k)
                    {
                        m = min(m, pd[row][k] + pd[k][row+step]);
                    }
                    // Save it.
                    pd[row][row+step] = m + cuts[row+step]-cuts[row];
                }
            }
        }
        cout << "The minimum cutting is " << pd[0][n+1] << "." << endl;
    }
}
