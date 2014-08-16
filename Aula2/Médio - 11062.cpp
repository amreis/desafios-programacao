#include <iostream>
#include <string>
#include <set>
#include <cctype>

using namespace std;

enum Status { WAITING_WORD, READING_WORD };

int main()
{
	Status status = WAITING_WORD;
	set<string> s;
	string x;
	string buffer;
	while (cin.good())
	{
		getline(cin, x);

		for (size_t i = 0; i < x.length(); ++i)
		{
			char c = tolower(x.at(i));
			switch (status)

			{
			case WAITING_WORD:
				if ((c >= 'a' && c <= 'z') || c == '-') {
					status = READING_WORD;
					buffer.push_back(c);
				}
				break;
			case READING_WORD:
				if ((c >= 'a' && c <= 'z') || c == '-') {
					buffer.push_back(c);
				}
				else if (! buffer.empty() || buffer == " " )
				{
					s.insert(buffer);
					buffer.clear();
					status = WAITING_WORD;
				}
				break;
			}
		}
		if (buffer.back() == '-')
		{
			buffer.erase(buffer.length() - 1);
			status = READING_WORD;
		}
		else if (! buffer.empty() || buffer == " ") {
		
			s.insert(buffer);
			buffer.clear();
			status = WAITING_WORD;
		}
	}
	for (set<string>::iterator i = s.begin(); i != s.end(); ++i)
		cout << *i << endl;
}
