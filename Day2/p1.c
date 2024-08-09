/* 2.1 : Aim of the program: Write a program in C to convert the first ‘n’ decimal numbers of a disc file to binary using recursion. Store the binary value in a separate disc file. 

Note# Read the value of ‘n’, source file name and destination file name from command line arguments. Display the decimal numbers and their equivalent binary numbers from the output file. 

Give the contents of the input disc file “inDec.dat” as 
30  75   2564  …

Contents of the output disc file “outBin.dat” as 
The binary equivalent of 30 is 0000000000011110
The binary equivalent of 75 is 0000000001001011
The binary equivalent of 2564 is 0000101000000100 

Terminal Input:
$gcc lab2q1.c -o lab2q1
$./lab2q1 150 inDec.dat outBin.dat

Output: Content of the first ‘n’ decimal and their equivalent binary numbers
*/
#include <stdio.h>
#include <stdlib.h>

void decimal_to_binary(int num, char *binary, int index) {
    if (index >= 16) {
        binary[16] = '\0'; // Null-terminate the binary string
        return;
    }
    
    // Recursive call to determine the binary digits
    decimal_to_binary(num / 2, binary, index + 1);
    
    // Store binary digit (0 or 1)
    binary[15 - index] = (num % 2) ? '1' : '0';
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *source_file = argv[2];
    char *destination_file = argv[3];

    FILE *in_file = fopen(source_file, "r");
    if (in_file == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *out_file = fopen(destination_file, "w");
    if (out_file == NULL) {
        perror("Error opening destination file");
        fclose(in_file);
        return 1;
    }

    int num;
    char binary[17]; // 16 bits + 1 for the null terminator
    int count = 0;

    while (fscanf(in_file, "%d", &num) == 1 && count < n) {
        decimal_to_binary(num, binary, 0);
        fprintf(out_file, "The binary equivalent of %d is %s\n", num, binary);
        count++;
    }

    fclose(in_file);
    fclose(out_file);

    // Display the contents of the output file
    out_file = fopen(destination_file, "r");
    if (out_file == NULL) {
        perror("Error opening destination file for reading");
        return 1;
    }

    char line[50];
    printf("Contents of the output file:\n");
    while (fgets(line, sizeof(line), out_file)) {
        printf("%s", line);
    }

    fclose(out_file);

    return 0;
}
