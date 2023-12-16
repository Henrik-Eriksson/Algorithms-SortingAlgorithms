#pragma once
#ifndef MAJS
#define MAJS

#define MAX_SIZE 100000


//This function is used to print out the contents of an array.
//It takes in a pointer to an integer array and the size of the array.
//It prints out the contents of the array.
void print_array(unsigned long* arr, int n);

//This function is used to generate an array of integers in a specified order. ordered,reverse,random,nearly
//It takes in a pointer to an integer array, the size of the array, and a string specifying the order.
//It generates an array of integers in the specified order.
void generate_input(unsigned long* arr, int n, const char* type);

//This function is used to generate an array of integers in nearly ordered order.
//It takes in a pointer to an integer array and the size of the array.
//It generates an array of integers in nearly ordered order.
void generate_nearly_ordered_input(unsigned long* arr, int n);

//This function is used to generate an array of integers in random order.
//It takes in a pointer to an integer array and the size of the array.
//It generates an array of integers in random order.
void generate_random_input(unsigned long* arr, int n);

//This function is used to generate an array of integers in descending order.
//It takes in a pointer to an integer array and the size of the array.
//It generates an array of integers in descending order.
void generate_reverse_ordered_input(unsigned long* arr, int n);

//This function is used to generate an array of integers in ascending order.
//It takes in a pointer to an integer array and the size of the array.
//It generates an array of integers in ascending order.
void generate_ordered_input(unsigned long* arr, int n);

#endif