#include <iostream>
#include <vector>

int main() {

    int *p = new int[3];
    int *p1 = new int[5];

    std::vector<int> v(3);
    std::vector<int> v1(3);

    v.resize(5);

    p[1] = 10;
    int *pp = &p[0];
//    v.

//    std::cout << p+1 << "\n";
//    std::cout << p+2 << "\n";
//    std::cout << p+3 << "\n";
//
//    std::cout << "\n";
//

    v[1] = 10;
    int *pv = &v[0];


//    std::cout << *(pp+1) << "\n";
    std::cout << p << "\n";

    std::cout << p1 << "\n";
//    std::cout << p1+1 << "\n";
//    std::cout << p1+2 << "\n";

//    std::cout << "\n";
//    std::cout << *(pv+1) << "\n";
    std::cout << &v[0] << "\n";
//    std::cout << &v[100] << "\n";
    std::cout << &v1[0] << "\n";


//    std::cout << *p << "\n";

    delete[] p;

    return 0;
}