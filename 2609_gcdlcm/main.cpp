#include <iostream>

int main() {
    int a, b;
    std::cin >> a;
    std::cin >> b;

    // 더 큰 수가 a이게 - a와 b 비교
    /// 1. compare 함수 없나?
    /// 2. 주소값으로 변환시키면 속도에 차이가?
    if (a<b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    // GCD - 유클리디안
    int r = a%b;
    while(r != 0){
        int tmp = a;
        a = b;
        b = tmp%b;
        r = b;
    }
    std::cout << a;



    return 0;
}