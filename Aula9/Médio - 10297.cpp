#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define EPS 0.0001
inline double eaten(double D, double d)
{
    double R = D/2;
    double r = d/2;
    return (M_PI*R*R*D) - (2*M_PI*R*R*R/3.0 - 2*M_PI*r*r*r/3.0 + M_PI*r*r*d);
}

int main()
{
    int D, V;
    double oldMid = 0;

    while (cin >> D >> V && !(D == 0 && V == 0))
    {
        double lo = 0, hi = D;
        double mid = (lo + hi) / 2.0;
        while (fabs(mid - oldMid) > EPS)
        {
            double e = eaten(D, mid);
            if (e > (double)V)
            {
                lo = mid;
                oldMid = mid;
            }
            else if (e < (double)V)
            {
                hi = mid;
                oldMid = mid;
            }

            mid = (lo + hi) / 2.0;
        }
        printf("%.3lf\n", mid);
    }
}
