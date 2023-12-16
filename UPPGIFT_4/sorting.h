#pragma once
#ifndef SORT_H
#define SORT_H


/*
    Selection Sort:
    Selection sort is a sorting algorithm, specifically an in-place comparison sort. It has O(n2) time complexity, making it inefficient on large lists, and generally performs worse than the similar insertion sort. Selection sort is noted for its simplicity, and it has performance advantages over more complicated algorithms in certain situations, particularly where auxiliary memory is limited.
    The algorithm divides the input list into two parts: the sublist of items already sorted, which is built up from left to right at the front (left) of the list, and the sublist of items remaining to be sorted that occupy the rest of the list. Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. The algorithm proceeds by finding the smallest (or largest, depending on sorting order) element in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element (putting it in sorted order), and moving the sublist boundaries one element to the right.
    The critical operation is performed: n(n-1)/2 times

    Insertion Sort:
    Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. However, insertion sort provides several advantages:
    Simple implementation: Jon Bentley shows a three-line C version, and a five-line optimized version
    Efficient for (quite) small data sets, much like other quadratic sorting algorithms
    More efficient in practice than most other simple quadratic (i.e., O(n2)) algorithms such as selection sort or bubble sort
    Adaptive, i.e., efficient for data sets that are already substantially sorted: the time complexity is O(kn) when each element in the input is no more than k places away from its sorted position
    Stable; i.e., does not change the relative order of elements with equal keys
    In-place; i.e., only requires a constant amount O(1) of additional memory space
    Online; i.e., can sort a list as it receives it
    The critical operation is performed: n(n-1)/2 times

    Quick Sort:
    Quicksort is a divide and conquer algorithm. Quicksort first divides a large array into two smaller sub-arrays: the low elements and the high elements. Quicksort can then recursively sort the sub-arrays.
    The steps are:
    Pick an element, called a pivot, from the array.
    Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
    Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.
    The base case of the recursion is arrays of size zero or one, which never need to be sorted.
    The critical operation is performed: n(n-1)/2 times
*/


void swap(unsigned long* a, unsigned long* b);
void selectionSort(unsigned long arr[], int arrLen, unsigned long* op);
void insertionSort(unsigned long arr[], int arrLen, unsigned long* op);
void quicksort(unsigned long A[], int l, int r, unsigned long* op);



#endif