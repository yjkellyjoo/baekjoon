//
// Created by Yeojin Kelly Joo on 2020/05/07.
//

#include <stdio.h>
#include <math.h>


int sum_divide_and_conquer(int n){
    if(n==1){
        return 1;
    }
    else if(n%2 == 1){
        return n+sum_divide_and_conquer(n-1);
    }
    else {
        return sum_divide_and_conquer(n/2)*2 + pow(n,2)/4;
    }
}

//int main(){
//    int n;
//
//    printf("n = ");
//    scanf("%d", &n);
//    printf("f(n) = %d\n", sum_divide_and_conquer(n));
//
//    return 0;
//}