// my_math.c
#include "my_math.h"

// user-defined function to check prime number
int checkPrimeNumber(int n) {
    int j, flag = 1;
    for (j = 2; j <= n / 2; ++j) {
        if (n % j == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

// sum of integer array
int sum(int *arr, int size) {
    int i = 0;
    int sum = 0;
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}