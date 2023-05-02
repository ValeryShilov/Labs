#include <iostream>
#include "Object.h"
#include "Pair.h"
#include "Rectangle.h"
#include "Vector.h"
using namespace std;

int main()
{
    Vector v(5);
    Pair a;
    cin >> a;
    Rectangle b;
    cin >> b;
    Object* p = &a;
    v.Add(p);
    p = &b;
    v.Add(p);
    cout << v << endl;
    return 0;
}
