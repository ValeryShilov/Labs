#include <iostream>
#include "Vector.h"
#include "error.h"

using namespace std;

int main()
{
    Vector v(5);

    try
    {
        Vector x(5);
        cin >> x;
        int n, n1;
        cout << x << endl;
        cin >> n;
        cout << x[n] << endl;
        cin >> n1;
        cout << x + n1 << endl;
        cin >> n1;
        cout << x - n1 << endl;
        
    }
    catch (error e)
    {
        e.what();
    }
    return 0;
}