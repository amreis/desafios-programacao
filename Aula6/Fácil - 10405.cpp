#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string s1, s2;
	while (true)
	{
		getline(cin, s1);
		if (cin.eof()) break;
		getline(cin, s2);
		if (cin.eof()) break;
		int matrix[s1.size()+1][s2.size()+1];
		memset(matrix, 0, sizeof(matrix));
		for (size_t i = 0; i < s1.size(); ++i)
		{
			for (size_t j = 0; j < s2.size(); ++j)
			{
				if (i == 0 && j == 0)
				{
					matrix[i][j] = s1.at(i) == s2.at(j);
				}
				else if (i == 0)
				{
					matrix[i][j] = max(int(s1.at(i) == s2.at(j)), matrix[i][j-1]);
				}
				else
				{
					if (s1.at(i) == s2.at(j))
						matrix[i][j] = 1 + matrix[i-1][j-1];
					else
						matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
				}
			}
		}
		cout << matrix[s1.size()-1][s2.size()-1] << endl;	
	}
}
