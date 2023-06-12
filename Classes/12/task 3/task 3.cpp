#include <iostream>
#include <map>
#include <D:\Labs\Lab 11 cl\task 2\Time.cpp>
#include <D:\Labs\Lab 11 cl\task 2\Time.h>
#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    Vector<Time> container(3);
    setlocale(LC_ALL, "Russian");
    int n;
    container.Print();
    cout << endl;

    Time a = container.max();
    container.add(a);
    container.Print();
    cout << endl;

    int b = container.min();
    container.del(b);
    container.Print();
    cout << endl;

    Time c = container.sred();
    container.add_sred(c);
    container.Print();
    cout << endl;
    return 0;
}