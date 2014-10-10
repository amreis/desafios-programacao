#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int m[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> m[i][j];
		}
	}
	// Calculate partial sums
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 && j == 0) continue;
			else if (i == 0)
			{
				m[i][j] += m[i][j-1];
			}
			else if (j == 0)
			{
				m[i][j] += m[i-1][j];
			}
			else
			{
				// Remove the diagonal above, since we will be adding it two times
				// if we do not (it is in m[i-1][j] and m[i][j-1])
				m[i][j] += (m[i-1][j] + m[i][j-1] - m[i-1][j-1]);
			}
		}
	}
	int maxSum = INT_MIN;
	// Here we calculate rectangles that go vertically from i to a and
	// horizontally from j to b
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int a = i; a < n; ++a)
			{
				for (int b = j; b < n; ++b)
				{
					int aux = m[a][b];
					if (i == 0 && j == 0)
					{
						;
					}
					else if (i == 0)
					{
						aux -= m[a][j-1];
					}
					else if (j == 0)
					{
						aux -= m[i-1][b];
					}
					else
					{
						aux -= (m[a][j-1] + m[i-1][b] - m[i-1][j-1]);
					}
					maxSum = max(maxSum,aux);
				}
			}
		}
	}
	cout << maxSum << endl;
}
