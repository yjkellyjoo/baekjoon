#include <iostream>

int bigger_value(int a, int b){
    int bigger;
    if(a<b){
        bigger = b;
    }
    else{
        bigger = a;
    }
    return bigger;
}


int main() {
    int arr_size, best_start, best_end;
    signed int *arr, *sum, best;

    std::cin >> arr_size;           // receive array size
    arr = new signed int[arr_size];         // allocate array with according array size
    sum = new signed int[arr_size];         // allocate sum with the same size

    for (int i = 0; i < arr_size; i++) {    // fill in the array
        std::cin >> arr[i];
    }
    fflush(stdin);

    // copy arr values to sum
    for (int i = 0; i < arr_size; ++i) {
        sum[i] = arr[i];
    }


    // 1. find the biggest number in the array. This is the best answer for now.
    best = arr[0];
    best_start = best_end = 0;
    for (int i = 1; i < arr_size; i++) {
        if (bigger_value(best, arr[i]) != best){
            best = bigger_value(best, arr[i]);
            best_start = best_end = i;
        }
    }

    // 2. The DP algorithm starting from level 2.
    for (int rounds = 1; rounds < arr_size; rounds++) {
        for (int sum_loc = 0; sum_loc < arr_size - rounds; sum_loc++) {
            sum[sum_loc] = sum[sum_loc] + arr[sum_loc+rounds];
            if (bigger_value(best, sum[sum_loc]) != best){
                best = bigger_value(sum[sum_loc], best);
                best_start = sum_loc;
                best_end = sum_loc + rounds;
            }
        }
    }

    delete[] sum;
    delete[] arr;

    // answer!
    for (int j = best_start; j <= best_end; ++j) {
        std::cout << arr[j] << " ";
    }

    return 0;
}
