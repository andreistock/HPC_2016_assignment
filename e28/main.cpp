#include <iostream>
#include "TriMatrix.cpp"
#include "TriMatrix.h"

// part (d)
int main() {
    TriMatrix m(3);
    m(1,0) = 1;
    m(2,1) = 1;
    m(0,0) = 2;
    m(1,1) = 2;
    m(2,2) = 2;
    m(0,1) = 3;
    m(1,2) = 3;

    m.print();

    TriMatrix n = m * 2.0;

    TriMatrix p = m + (n / 2.0) - (m * 0.5);

    n.print();
    p.print();
}
