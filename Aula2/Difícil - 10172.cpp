#include <iostream>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int main()
{
	int SET;
	cin >> SET;
	
	for (int nTimes = 0; nTimes < SET; ++nTimes)
	{
		set<int> empties;
		int time = 0;
		int n, s, q;
		cin >> n >> s >> q;
		vector<queue<int>> bPlats(n);
		stack<int> carrier;
		for (int i = 0; i < n; ++i)
		{
			int nCargoes;
			cin >> nCargoes;
			for (int j = 0; j < nCargoes; ++j)
			{
				int aux;
				cin >> aux;
				bPlats[i].push(aux - 1);

			}
		}
		int carrierPos = 0;

		while (true) {
			bool worked = true;
			while (worked)
			{
				worked = false;
				if (carrier.empty())
				{
					break;
				}
				if (carrier.top() == carrierPos)
				{
					carrier.pop();
					time++;
					worked = true;
				}
				else if (bPlats[carrierPos].size() < q)
				{
					int x = carrier.top();
					carrier.pop();
					bPlats[carrierPos].push(x);
					time++;
					worked = true;
				}
				else
				{
					break;
				}
			}
			while (carrier.size() < s && !bPlats[carrierPos].empty())
			{
				int x = bPlats[carrierPos].front();
				bPlats[carrierPos].pop();
				carrier.push(x);
				time++;
			}
			if (bPlats[carrierPos].empty())
			{
				empties.insert(carrierPos);
			}
			else
			{
				auto pos = empties.find(carrierPos);
				if (pos != empties.end())
					empties.erase(pos);
			}
			if (empties.size() == n && carrier.empty())
				break;
			carrierPos = (carrierPos+1) % n;
			time += 2;
			
		}
		cout << time << endl;
	}
	
	return 0;
}
