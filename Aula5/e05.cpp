#include <iostream>
#include <vector>

using namespace std;

int coins[] = { 1, 5, 10, 25, 50 };

vector<vector<long long> > pd(5, vector<long long>(30001, 0));

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j <= 30000; ++j)
		{
			if (i == 0 || j <= 1) { pd[i][j] = 1; }
			else if (coins[i] <= j)
			{
				pd[i][j] += pd[i-1][j] + pd[i][j-coins[i]];
			}
			else { pd[i][j] = pd[i-1][j]; }
		}
		
	}
	int n;
	while (cin >> n)
	{
		long long maxX = pd[4][n];

		if (maxX == 1)
		{
			cout << "There is only 1 way to produce " << n << " cents change." << endl;
		}
		else
			cout << "There are " << maxX << " ways to produce " << n << " cents change." << endl;
		
	}
}

