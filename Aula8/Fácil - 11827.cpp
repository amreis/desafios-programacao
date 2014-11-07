#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;
set<int> numbers;
typedef reverse_iterator<set<int>::iterator> riter;

int gcd (int a, int b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (int __n = 0; __n < n; ++__n)
	{

		numbers.clear();
		string s;
		getline(cin, s); 
		stringstream ss(s);
		int x;
		while (ss >> x)
		{

			numbers.insert(x);
		}
		
		int maxGCD = -1;
		typedef std::set<int>::iterator iter_type;

  		std::reverse_iterator<iter_type> it, jt;
  		bool flag = false;
		for(it = numbers.rbegin(); it != numbers.rend(); ++it)
		{
			flag = false;
			if (maxGCD > *it) break;
			for (jt = (++it); jt != numbers.rend(); ++jt)
			{
				if (!flag) { --it; flag = true; }

				maxGCD = max(maxGCD, gcd(*it, *jt));
				if (maxGCD > *jt) break;
			}
			if (!flag) --it;
		}
		cout << maxGCD << endl;
	}
}
