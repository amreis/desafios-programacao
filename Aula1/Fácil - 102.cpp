#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,string> IS;
int main()
{
    while (cin.good())
    {
        int bins[3][3];
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cin >> bins[i][j];
                if (!cin.good()) // || cin.eof())
                    return 0;
            }
        }
        
        vector<IS> possibilities;
        
        // BGC //
        
        possibilities.push_back(
            IS(
                bins[1][0]+bins[2][0]+
                bins[0][1]+bins[2][1]+
                bins[0][2]+bins[1][2],
                "BGC"
            )
        );
        
        // BCG //
        possibilities.push_back(
            IS(
                bins[1][0]+bins[2][0]+
                bins[0][2]+bins[2][2]+
                bins[0][1]+bins[1][1],
                "BCG"
            )
        );
        // GBC //
        possibilities.push_back(
            IS(
                bins[1][1]+bins[2][1]+
                bins[0][0]+bins[2][0]+
                bins[0][2]+bins[1][2],
                "GBC"
            )
        );
        // GCB //
        possibilities.push_back(
            IS(
                bins[1][1]+bins[2][1]+
                bins[0][2]+bins[2][2]+
                bins[0][0]+bins[1][0],
                "GCB"
            )
        );
        // CGB
        possibilities.push_back(
            IS(
                bins[1][2]+bins[2][2]+
                bins[0][1]+bins[2][1]+
                bins[0][0]+bins[1][0],
                "CGB"
            )
        );
        // CBG
        possibilities.push_back(
            IS(
                bins[1][2]+bins[2][2]+
                bins[0][0]+bins[2][0]+
                bins[0][1]+bins[1][1],
                "CBG"
            )
        );
        
        std::sort(possibilities.begin(), possibilities.end());
        IS res = possibilities[0];
        // cout << "(" << res.first << ", " << res.second << ");" << endl;
        cout << res.second << " " << res.first << endl;
    }
}
