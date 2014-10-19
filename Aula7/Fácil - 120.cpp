#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, vector<int> v)
{
    if (v.empty()) return os;
    for (size_t i = 0; i < v.size() - 1; ++i)
    {
        os << v[i] << " ";
    }
    os << v[v.size()-1];
    return os;
}

void inline flip(vector<int>& v, int at)
{
    cout << at << " ";
    int x = v[v.size()-at];
    vector<int> aux(v.begin(), v.end());
    int j = 0;
    for (int i = v.size()-at; i >= 0; --i)
    {
        aux[i] = v[j]; j++;
    }
    aux[0] = x;
    v = aux;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        stringstream s(line);
        vector<int> diameters;
        int x;
        while (s >> x)
            diameters.push_back(x);
        cout << diameters << endl;
        for (size_t i = 0; i < diameters.size(); ++i)
        {
            int maior = 0;
            bool isSorted = true;
            for (size_t j = 1; j < diameters.size() - i; ++j)
            {
                if (diameters[j] < diameters[j-1]) isSorted = false;
                if (diameters[maior] < diameters[j])
                    maior = j;
            }
            if (isSorted)
            {
                cout << "0" << endl;
                break;
            }
            else if (maior == 0)
            {
                flip(diameters, i+1);
            }
            else
            {
                flip(diameters, diameters.size()-maior);
                flip(diameters, i+1);
            }
        }
    }

    return 0;
}
