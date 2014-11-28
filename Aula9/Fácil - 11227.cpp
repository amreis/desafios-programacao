#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#define EPS 0.00000001
using namespace std;

class point
{
public:
    double x;
    double y;
    bool operator==(const point& other) const
    {
        return (x == other.x && y == other.y);
    }
    bool operator< (const point& other) const
    {
        return (x < other.x || (x >= other.x && y < other.y));
    }
};

int main()
{
    int t;
    cin >> t;
    for (int _t = 0; _t < t; ++_t)
    {
        int n;
        cin >> n;
        set<point> gnus;
        for (int i = 0; i < n; ++i)
        {
            point y;
            cin >> y.x >> y.y;
            gnus.insert(y);
        }
        int maxNAligned = -1;
        if (gnus.size() == 1)
        {
            cout << "Data set #" << _t + 1 << " contains a single gnu." << endl;
        }
        else
        {
            for (set<point>::iterator i = gnus.begin(); i != gnus.end(); ++i)
            {
                for (set<point>::iterator j = i; j != gnus.end(); ++j)
                {
                    if (i == j) continue;
                    point p1, p2;
                    p1 = *i, p2 = *j;
                    int nAligned = 2;
                    const double x0 = p1.x, y0 = p1.y;
                    if (p2.x == x0)
                    {
                        // vertical
                        for (set<point>::iterator k = gnus.begin(); k != gnus.end(); ++k)
                        {
                            if (k == i || k == j) continue;
                            if (k->x == x0) nAligned++;
                        }
                    }
                    else {
                    const double m = (p2.y - y0)/(p2.x - x0);
                    for (set<point>::iterator k = gnus.begin(); k != gnus.end(); ++k)
                    {
                        if (k == i || k == j) continue;
                        double lineResult = m*(k->x - x0) + y0;
                        if (fabs(lineResult - k->y) <= EPS) nAligned++;
                    }
                    }
                    maxNAligned = max(maxNAligned, nAligned);
                }
            }
            cout << "Data set #" << _t + 1 << " contains " << gnus.size() << " gnus, out of which a maximum of " << maxNAligned << " are aligned." << endl;
        }
    }
}
