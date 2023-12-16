#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "stdio.h"
#include "stdlib.h"


void swap(unsigned long* a, unsigned long* b)
{
    unsigned long temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(unsigned long arr[], int arrLen, unsigned long* op)
{
    int criticalCounter = 0;
    for (int i = 0; i <= (arrLen - 2); i++)
    {
        int min = i;
        for (int j = i + 1; j <= (arrLen - 1); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }

            swap(&arr[i], &arr[min]);
            (*op)++;
        }
    }
}

void insertionSort(unsigned long arr[], int arrLen, unsigned long* op)
{
    int criticalCounter = 0;
    int v = 0;
    int j = 0;
    for(int i = 1; i < (arrLen-1); i++)
    {
        v = arr[i];
        j = (i - 1);
        //criticalCounter++; a men swappen är nog bara den kritiska operationen

        if (!(j >= 0 && arr[j] > v)) (*op)++;
        while(j >= 0 && arr[j] > v)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*op)++;
        }
        
    }
    arr[j + 1] = v;
}


void quicksort(unsigned long A[], int l, int r, unsigned long* op)
{
    //printf("%d\n", *criticalCounter);
    if (l < r)
    {
        int s = hoarePartition(A, l, r, op);
        //int s = partition(A, l, r, op);
        quicksort(A, l, s - 1, op);
        quicksort(A, s + 1, r, op);
    }
}

int hoarePartition(unsigned long arr[], int low, int high, unsigned long*op)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do
        {
            i++;
            (*op)++;
        } while (arr[i] < pivot);

        do
        {
            j--;
            (*op)++;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
        //(*op)++;
    }
}
