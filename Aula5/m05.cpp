#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int matrix[n][n];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> matrix[i][j];
            }
        }
    }
}
