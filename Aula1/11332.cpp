#include <iostream>

using namespace std;

typedef long int li;


int main()
{
    li n;
    while (cin >> n)
    {
        li sumOfDigits = n;
        if (n == 0) break;
        while (! (n < 10) )
        {
            sumOfDigits = 0;
            for (int i = n; i > 0; i /= 10)
            {
                sumOfDigits += i % 10;  
            }
            n = sumOfDigits;
        }
        cout << sumOfDigits << endl;
    }
    
    return 0;
}
