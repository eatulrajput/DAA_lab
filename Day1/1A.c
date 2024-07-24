// Aim of the program: Write a program to find out the second smallest and second largest
// element stored in an array of n integers.

// Input: Size of the array is ‘n’ and read ‘n’ number of elements from a disc file.
// Output: Second smallest, Second largest.

#include <stdio.h>
#include <limits.h>

void findSecondSmallestAndLargest(int arr[], int n) {
    if (n < 2) {
        printf("Array needs to have at least two elements\n");
        return;
    }

    int firstSmallest = INT_MAX, secondSmallest = INT_MAX;
    int firstLargest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        // Find the smallest and second smallest
        if (arr[i] < firstSmallest) {
            secondSmallest = firstSmallest;
            firstSmallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != firstSmallest) {
            secondSmallest = arr[i];
        }

        // Find the largest and second largest
        if (arr[i] > firstLargest) {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != firstLargest) {
            secondLargest = arr[i];
        }
    }

    if (secondSmallest == INT_MAX) {
        printf("No second smallest element\n");
    } else {
        printf("Second Smallest: %d\n", secondSmallest);
    }

    if (secondLargest == INT_MIN) {
        printf("No second largest element\n");
    } else {
        printf("Second Largest: %d\n", secondLargest);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array needs to have at least two elements\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findSecondSmallestAndLargest(arr, n);

    return 0;
}