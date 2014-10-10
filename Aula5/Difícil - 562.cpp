#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int _n = 0; _n < n; ++_n)
	{
		int m;
		cin >> m;
		int mySum = 0;
		vector<int> coins;
		coins.push_back(0);
		for (int i = 0; i < m; ++i)
		{
			int x;
			cin >> x;
			coins.push_back(x);
			mySum += x;
		}
		sort(coins.begin(), coins.end());
		vector<bool> pd(mySum+1, false);
		int helper = 0;
		for (size_t i = 0; i < coins.size(); ++i)
		{
			for (int j = 0; j <= mySum; ++j)
			{
				if (j > helper)
				{
					helper += coins[i+1];
					break;
				}
				if (j >= coins[i])
				{
					pd[j] = pd[j] ||  (pd[j-coins[i]]);
				}
				pd[j] = pd[j] || (coins[i] == j);
				
			}
		}
		int minDiff = INT_MAX;
		for (int j = 0; j <= ((mySum >> 1) | 1); ++j)
		{
			if (pd[j])
			{
				int k =	abs(2*j - mySum);


				minDiff = min(
					minDiff, 
					k
					);
			}
		}
		cout << minDiff << endl;
	}
}
