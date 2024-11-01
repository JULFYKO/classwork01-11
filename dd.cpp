#include "dd.h"
#include <iostream>
using namespace std;

template <typename T>
T sum(T a, T b)
{
    return a + b;
}

int main()
{

    Matrix<int, 4, 4> m(8);
    m.print();
    m(2, 2) = 77;
    cout << m + 2 << endl;

    Matrix<double, 3, 3> d(3.3);
    cout << d << endl;
    d = d + 3.0;
    cout << d << endl;

    Matrix<> mm(11);
    cout << mm << endl;

    Matrix<string, 5, 5> s("test");
    cout << s << endl;
    s(3, 3) = "ok";
    cout << s << endl;

    Matrix<int, 4, 4> m2(8);
    cout << (m == m2) << endl;
    cout << (m != m2) << endl;
    cin >> m2;
    cout << m2;

    return 0;
}
