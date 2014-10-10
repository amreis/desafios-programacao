#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef unsigned long long ull;

int main()
{
	int n, k;
	int matrix[101][101];
	memset(matrix, 0, sizeof(matrix));
	
	for (int i = 0; i < 101; ++i)
	{
		for (int j = 0; j < 101; ++j)
		{
			if (i <= 1) matrix[i][j] = 1;
			else if (j <= 1) matrix[i][j] = i;
			else if (i == 2)
			{
				matrix[i][j] = j + 1;
			}
			else
			{
				matrix[i][j] = (matrix[i-1][j] % 1000000) + (matrix[i][j-1] % 1000000);
			}
		}
	}
	
	while (cin >> n >> k && !(n == 0 && k == 0))
	{
		cout << matrix[k][n] % 1000000 << endl;
	}


}

