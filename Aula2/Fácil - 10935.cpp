#include <iostream>
#include <list>

using namespace std;

ostream& operator<<(ostream& os, list<int> l)
{
	if (l.empty()) return os;
	
	if (l.size() == 1)
	{
		os << l.front();
		return os;
	}
	else
	{
		while (! l.empty())
		{
			if (l.size() == 1)
			{
				os << l.front();
			}
			else
			{
				os << l.front() << ", ";
			}
			l.pop_front();
		}
		return os;
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		list<int> deck;
		list<int> discarded;
		if (n == 0) return 0;
		for (int i = 1; i <= n; ++i)
		{
			deck.push_back(i);
		}
		while (deck.size() >= 2)
		{
			int first = deck.front();
			deck.pop_front();
			discarded.push_back(first);
			deck.push_back(deck.front());
			deck.pop_front();
		}
		if (! discarded.empty() )
			cout << "Discarded cards: " << discarded << endl;
		else
			cout << "Discarded cards:" << endl;
		cout << "Remaining card: " << deck.front() << endl;
	}
}
