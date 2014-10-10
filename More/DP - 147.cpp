#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int c[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };

long long int pd[30000/5 + 1] = {0};

int main()
{
	for (int m = 0; m < 11; ++m)
	{
		for (int v = 0; v <= 30000/5; ++v)
		{
			if (m == 0)
			{
				pd[v] = 1;
			}
			else if (5*v >= c[m])
			{
				pd[v] += pd[v-(c[m]/5)];
			}
		}
	}
	float val;
	while (cin >> val && val != 0.00)
	{
		int x = round(val * 100);
		printf("%6.2f", val);
		printf("%17lld\n", pd[x/5]);
	}
}
