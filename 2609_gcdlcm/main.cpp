#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<bool> bool_vec_t;
typedef std::vector<int> int_vec_t;

void gcd(int a, int b);
void getPrime(bool_vec_t prime, int a);
void getMultiples(int_vec_t factor, const bool_vec_t prime, int a);
void lcm(int a, int b);


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

    gcd(a, b);
    lcm(a, b);

    return 0;
}


/*
 * find GCD using Euclidean Algorithm
 * @param
 */
void gcd(int a, int b) {
    int r = a%b;
    while(r != 0){
        int tmp = a;
        a = b;
        b = tmp%b;
        r = b;
    }
    std::cout << a << std::endl;
}

/*
 * prime factorization using Sieve of Eratosthenes
 */
void getPrime(bool_vec_t prime, int a) {
    prime[0] = false;
    prime[1] = false;

    for (int p = 2; p != a; ++p) {
        if (prime[p]) {
            for (int i = p*p; i <= a+1; i+=p) {
                prime[i] = false;
            }
        }
    }
}

/*
 * find multiples
 */
void getMultiples(int_vec_t factor, const bool_vec_t prime, int a) {
    for (int p = 0; p < a+1; ++p) {
        if (prime[p]) {
            while (a%p == 0) {
                a /= p;
                factor[p]++;
            }
        }
    }
}

/*
 *
 */
void lcm(int a, int b) {
    bool_vec_t prime(a+1, true);
    getPrime(prime, a);

    int_vec_t a_factor(a+1, 0);
    int_vec_t b_factor(b+1, 0);

    getMultiples(a_factor, prime, a);
    getMultiples(b_factor, prime, b);

    int factor_size = a_factor.size();
    int biggest_factor[factor_size];
    for (int i = 0; i < factor_size; ++i) {
        if (a_factor[i] <= b_factor[i]) {
            biggest_factor[i] = b_factor[i];
        }
        else {
            biggest_factor[i] = a_factor[i];
        }
    }

    int lcm = 1;
    for (int i = 2; i < factor_size; ++i) {
        lcm *= (int) pow(i, biggest_factor[i]);
    }

    std::cout << lcm << std::endl;
}
