#include <iostream>

using namespace std;

struct Point {
	int x;
	int y;
};

int main()
{
	int K;
	while (cin >> K)
	{
		if (K == 0) return 0;
		Point div;
	
		cin >> div.x >> div.y;

		for (int k = 0; k < K; ++ k)
		{
			Point res;
			cin >> res.x >> res.y;
			
			if (res.x == div.x || res.y == div.y)
			{
				cout << "divisa" << endl;
			}
			else if (res.x > div.x && res.y > div.y)
			{
				cout << "NE" << endl;
			}
			else if (res.x < div.x && res.y > div.y)
			{
				cout << "NO" << endl;
			}
			else if (res.x > div.x && res.y < div.y)
			{
				cout << "SE" << endl;
			}
			else
				cout << "SO" << endl;
		}
	}
}

