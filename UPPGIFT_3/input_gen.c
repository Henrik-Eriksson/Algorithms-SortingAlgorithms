#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "stdio.h"
#include "stdlib.h"
#include "sorting.h"

void swap(unsigned long* a, unsigned long* b);
//This function is used to print out the contents of an array.
//It takes in a pointer to an integer array and the size of the array.
//It prints out the contents of the array.
void print_array(unsigned long* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//This function is used to generate an array of integers in ascending order.
//It takes in a pointer to an integer array and the size of the array.
//It generates an array of integers in ascending order.
void generate_ordered_input(unsigned long* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

//This function is used to generate an array of integers in descending order.
//It takes in a pointer to an integer array and the size of the array.
//It generates an array of integers in descending order.
void generate_reverse_ordered_input(unsigned long* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

//This function is used to generate an array of integers in random order.
//It takes in a pointer to an integer array and the size of the array.
//It generates an array of integers in random order.
void generate_random_input(unsigned long* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
}

//This function is used to generate an array of integers in nearly ordered order.
//It takes in a pointer to an integer array and the size of the array.
//It generates an array of integers in nearly ordered order.
void generate_nearly_ordered_input(unsigned long* arr, int n) {
    generate_ordered_input(arr, n);
    int swaps = n * 0.04;
    for (int i = 0; i < swaps; i++) {
        int a = rand() % n;
        int b = rand() % n;
        swap(&arr[a], &arr[b]);
    }
}

//This function is used to generate an array of integers in a specified order.
//It takes in a pointer to an integer array, the size of the array, and a string specifying the order.
//It generates an array of integers in the specified order.
void generate_input(unsigned long* arr, int n, const char* type) {
    if (strcmp(type, "ordered") == 0) {
        generate_ordered_input(arr, n);
    }
    else if (strcmp(type, "reverse") == 0) {
        generate_reverse_ordered_input(arr, n);
    }
    else if (strcmp(type, "random") == 0) {
        generate_random_input(arr, n);
    }
    else if (strcmp(type, "nearly") == 0) {
        generate_nearly_ordered_input(arr, n);
    }
    else {
        printf("Invalid input type.\n");
    }
}


