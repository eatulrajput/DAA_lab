// Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain
// some duplicate values and store them into an array. Perform the following operations on the
// array.
// a) Find out the total number of duplicate elements.
// b) Find out the most repeating element in the array.
// Input:
// Enter how many numbers you want to read from file: 15
// Output:
// The content of the array: 10 40 35 47 68 22 40 10 98 10 50 35 68 40 10
// Total number of duplicate values = 4
// The most repeating element in the array = 10

#include <stdio.h>

int main() {
    int n, i, j, count, maxCount = 0, mostRepeated;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Finding total number of duplicate elements
    int duplicateCount = 0;
    int foundDuplicate;
    for (i = 0; i < n; i++) {
        foundDuplicate = 0;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                foundDuplicate = 1;
                break;
            }
        }
        if (foundDuplicate) {
            continue;
        }
        count = 0;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > 0) {
            duplicateCount++;
        }
    }
    printf("Total number of duplicate values = %d\n", duplicateCount);

    // Finding the most repeating element
    for (i = 0; i < n; i++) {
        count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostRepeated = arr[i];
        }
    }
    printf("The most repeating element in the array = %d\n", mostRepeated);

    return 0;
}
