#include <iostream>

int gcd(int a, int b);
void selectionSort(int size, int arr[]);

int main() {
    // 변수 선언
    int testCase;
    std::cin >> testCase;
    int result[testCase];

    // 입력 받기
    for (int i = 0; i < testCase; ++i) {
        int intCount;
        std::cin >> intCount;
        int intNum[intCount];
        for (int j = 0; j < intCount; ++j) {
            std::cin >> intNum[j];
        }
        result[i] = 0;

        // 내림차순 정렬
        selectionSort(intCount, intNum);

        // gcd 구하기
        for (int j = 0; j < intCount-1; ++j) {
            for (int k = j+1; k < intCount; ++k) {
                result[i] += gcd(intNum[j], intNum[k]);
            }
        }
    }

    for (int i = 0; i < testCase; ++i) {
        std::cout << result[i] << std::endl;
    }

    return 0;
}

/*
 * find GCD using Euclidean Algorithm
 * @param   biggerInt, smallerInt
 * @return  gcd
 */
int gcd(int a, int b) {
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

/*
 * selection sort in non-increasing order
 * @param   array size, array address
 */
void selectionSort(int size, int* arr){
    int biggest;
    for (int i = 0; i < size-1 ; i++) {
        biggest = i;
        for (int j = i+1; j < size; ++j) {
            if (arr[j] > arr[biggest])
                biggest = j;
        }
        int tmp = arr[i];
        arr[i] = arr[biggest];
        arr[biggest] = tmp;
    }
}