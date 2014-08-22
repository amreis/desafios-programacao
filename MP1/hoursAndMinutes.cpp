#include <iostream>
#include <cmath>

using namespace std;

bool ang[181];

int main()
{
	int h = 0, m = 0;
	for (int i = 0; i < 720; ++i)
	{
		if (m == 60) m = 0;
		if (h == 12) h = 0;
		int angle = min(abs(m-h) * 6, abs(60-(m-h)) * 6);
		ang[angle] = true;
		if (i % 12 == 0)
			h++;
		m++;
		
	}
	int a;
	while (cin >> a)
	{
		if (ang[a])
			cout << 'Y' << endl;
		else
			cout << 'N' << endl;
	}
}
