#include <iostream>

using namespace std;

int cycleLength(int k)
{
	int l = 1;
	if (k == 1) return l;
	
	else
	while (k != 1)
	{
		if (k % 2 == 0)
			k /= 2;
			
		else
			k = 3*k + 1;
		l++;
	}
	
	return l;
}

int main()
{
	int i, j;
	while (cin >> i >> j)
	{
		int auxI, auxJ;
		auxI = min(i,j);
		auxJ = max(i,j);
		int max = cycleLength(auxI);
		for (int k = auxI+1; k <= auxJ; ++k)
		{
			int cLength = cycleLength(k);
			if (cLength > max) max = cLength;
		}
		
		cout << i << " " << j << " " << max << endl;
	}
}
