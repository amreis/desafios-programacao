#include <iostream>
#include <cstring>

using namespace std;

bool isPrime[1000002];

int main()
{
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i <= 1000000; ++i)
	{
		if (isPrime[i])
		{

			for (int j = 2*i; j <= 1000000; j += i)
				isPrime[j] = false;
		}
	}
	int n;
	while (cin >> n && n != 0)
	{
		int diff = -1;
		int a = 0, b = 0;
		for (int i = 2; i <= n/2 + 1; ++i)
		{
			if (isPrime[i] && isPrime[n-i])
			{
				if (diff < (n - 2*i))
				{
					diff = 2*i - n;
					a = i; b = n - i;
					break;
				}
			}
		}
		if (diff == -1)
		{
			cout << "Goldbach's conjecture is wrong." << endl;
		} else {
			cout << n << " = " << a << " + " << b << endl;
		}
	}
}
