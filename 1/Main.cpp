#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include "Header.h"
#include "Source.cpp"

int main()
{
    RCS p1(10, 20);
    PCS p2(1, 50);

    p1.print();
    cout << endl;

    p2.print();
    cout << endl;

    p1.convert().print();
    cout << endl;
    p1.convert().convert().print();
    cout << endl;

    RCS a(1, 1);
    RCS b(4, 5);

    cout << "Distance between "
         << a.to_string() << " and "
         << b.to_string() << " is "
         << distance(a, b) << endl;

    return 0;
}