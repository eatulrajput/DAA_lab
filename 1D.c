// Aim of the program: Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2
// elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p &
// q. Parameter p1 be the starting address of the array and p2 be the number of elements to be
// rotated.
// Input:
// Enter an array A of size N (9): 11 22 33 44 55 66 77 88 99
// Call the function ROTATE_RIGHT(A, 5)
// Output:
// Before ROTATE: 11 22 33 44 55 66 77 88 99
// After ROTATE: 55 11 22 33 44 66 77 88 99

#include <stdio.h>

void EXCHANGE(int *arr, int p, int q) {
    int temp = arr[p];
    arr[p] = arr[q];
    arr[q] = temp;
}

void ROTATE_RIGHT(int *arr, int p2) {
    if (p2 <= 1) return;

    // Store the last element of the first p2 elements
    int last_element = arr[p2 - 1];

    // Shift elements to the right by one position
    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(arr, i, i - 1);
    }

    // Place the stored last element at the first position
    arr[0] = last_element;
}

int main() {
    int A[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int N = sizeof(A) / sizeof(A[0]);
    int p2 = 5;

    // Output before ROTATE_RIGHT
    printf("Before ROTATE: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Call the function
    ROTATE_RIGHT(A, p2);

    // Output after ROTATE_RIGHT
    printf("After ROTATE: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}