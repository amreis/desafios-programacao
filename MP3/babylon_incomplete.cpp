#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, int> iii;

struct Height {
	bool operator()(iii a, iii b)
	{
		return (a.second > b.second) || (! (a.second > b.second) && 
			(a.first > b.first) );
	}
} sortByHeight;

struct rev {

	bool operator()(iii a, iii b)
	{ return a >= b; }
} _rev;

bool myless(iii a, iii b)
{
	if (a == b) return false;
	if (a.first.first < b.first.first && a.first.second < b.first.second)
		return true;
	else if (a.first.second < b.first.first && a.first.first < b.first.second)
		return true;
	return false;
	
}

int main()
{
	int n;

	while (cin >> n && n != 0)
	{
		vector<iii> boxes;
		for (int i = 0; i < n; ++i)
		{
			iii n;
			cin >> n.first.first >> n.first.second >> n.second;
			boxes.push_back(n);
			boxes.push_back(iii(ii(n.first.second, n.first.first), n.second));
			boxes.push_back(iii(ii(n.second, n.first.first), n.first.second));
			boxes.push_back(iii(ii(n.first.first, n.second), n.first.second));
			boxes.push_back(iii(ii(n.first.second, n.second), n.first.first));
			boxes.push_back(iii(ii(n.second, n.first.second), n.first.first));
		}			

		vector<iii> byHeight(boxes.begin(), boxes.end());
		sort(boxes.begin(), boxes.end(), _rev);

		int matrix[boxes.size()][boxes.size()];
		int gmax = 0;
		for (int i = 0; i < boxes.size(); ++i)
		{
			for (int j = 0; j < boxes.size(); ++j)
			{
				matrix[i][j] = ((myless(boxes[i], boxes[j]) ? boxes[i].second + boxes[j].second : 0));
				if (i > 0 && j > 0)
				{
					if (matrix[i-1][j-1] > 0 && myless(boxes[i], boxes[j]))
					{
						matrix[i][j] = max(matrix[i][j],
							matrix[i-1][j-1] + boxes[j].second - boxes[i].second);
					}
				}
				gmax = max(gmax, matrix[i][j]);	
			}
		}
		
		cout << gmax << endl;
	}
}
