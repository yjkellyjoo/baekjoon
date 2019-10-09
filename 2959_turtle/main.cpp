#include <iostream>

void selectionSort(int size, int* arr){
    int smallest;
    for (int i = 0; i < size-1 ; i++) {
        smallest = i;
        for (int j = i+1; j < size; ++j) {
            if (arr[j] < arr[smallest])
                smallest = j;
        }
        int tmp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = tmp;
    }
//    std::cout << arr[0] << arr[1] << arr[2] << arr[3] << std::endl;
    std::cout << arr[0] * arr[2];
}

int main() {
    int arr[4] = {0, };
    std::cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

    selectionSort(4, &arr[0]);

    return 0;
}