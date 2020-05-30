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
    int num_of_tests, arr_size, best_start, best_end;
    signed int *arr, *sum, *best;

    scanf("%d", &num_of_tests);     // receive number of tests
    best = new signed int[num_of_tests];    // allocate best array with the size of number of tests
    for (int j = 0; j < num_of_tests; ++j) {    // for each test,

        scanf("%d", &arr_size);         // receive array size
        arr = new signed int[arr_size];         // allocate array with according array size

        for (int i = 0; i < arr_size; i++) {    // fill in the array
            scanf("%d", &arr[i]);
        }
        fflush(stdin);

        // 1. find the biggest number in the array. This is the best answer for now.
        best[j] = arr[0];
        for (int i = 1; i < arr_size; i++) {

            best[j] = bigger_value(best[j], arr[i]);

        }


        sum = new signed int[arr_size];
        for (int i = 0; i < arr_size; ++i) {    // copy arr values to sum
            sum[i] = arr[i];
        }

        for (int rounds = 1; rounds < arr_size; rounds++) {
            for (int sum_loc = 0; sum_loc < arr_size - rounds; sum_loc++) {
                sum[sum_loc] = sum[sum_loc] + arr[sum_loc+rounds];
                best[j] = bigger_value(sum[sum_loc], best[j]);
            }
        }

        delete[] sum;
        delete[] arr;
    }

    // answer!
    for (int j = 0; j < num_of_tests; ++j) {
        printf("%d\n", best[j]);
    }
    delete[] best;

    return 0;
}
