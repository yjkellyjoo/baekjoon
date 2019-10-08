#include <iostream>

int gcd(int a, int b);

int main() {
    int testCase;
    std::cin >> testCase;
    int result[testCase];
    for (int i = 0; i < testCase; ++i) {
        int intCount;
        std::cin >> intCount;
        int intNum[intCount];
        for (int j = 0; j < intCount; ++j) {
            std::cin >> intNum[j];
        }

        result[i] = intNum[0];
        for (int j = 1; j < intCount; ++j) {
            if (result[i] < intNum[j]) {
                result[i] = intNum[j];
                intNum[j] = intNum[j-1];
            }
            result[i] = gcd(result[i], intNum[j]);
        }
    }

    for (int i = 0; i < testCase; ++i) {
        std::cout << result[i] << std::endl;
    }

    return 0;
}

/*
 * find GCD using Euclidean Algorithm
 * @param
 */
int gcd(int a, int b) {
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}