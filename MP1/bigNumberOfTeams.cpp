#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	cin.ignore();
	for (int i = 0 ; i < T; ++i)
	{
		string team, judge;
		getline(cin, team);
		getline(cin, judge);

		if (team.length() != judge.length())
		{
			size_t p1 = 0, p2 = 0;
			bool wa = false;
			while (p1 < team.length() && p2 < judge.length())
			{
				while (team.at(p1) == ' ')
				{
					++p1;
				}
				if (team.at(p1) != judge.at(p2))
				{
					cout << "Case " << i+1 << ": Wrong Answer" << endl;
					wa = true;
				}
				++p1; ++p2;
			}
			while (p1 < team.length() && team.at(p1) == ' ')
			{
				p1 ++;
			}
			if (p1 == team.length() && p2 == judge.length())
			{
				cout << "Case " << i+1 << ": Output Format Error" << endl;
			}
			else if (!wa && (p1 != team.length() || p2 != judge.length()))
			{
				wa = true;
				cout << "Case " << i+1 << ": Wrong Answer" << endl;
			}
			
		}
		else
		{
			bool wa = false;
			for (size_t x = 0; x < team.length(); ++x)
			{
				if (team.at(x) != judge.at(x))
				{
					wa = true;
					cout << "Case " << i + 1 << ": Wrong Answer" << endl;

				}
			}
			if (!wa)
			{
				cout << "Case " << i+1 << ": Yes" << endl;
			}
		}
	}
}
