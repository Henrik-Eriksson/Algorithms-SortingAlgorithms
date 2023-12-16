#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "sorting.h"
#include "input_gen.h"
#include "time.h"

unsigned long* threeAlgosOneRun(unsigned long arrGen[], int length, const char* type);
void copyArray(unsigned long arr[], unsigned long copy[], int size);
unsigned long sumOfArray(unsigned long a[], unsigned long len);
unsigned long criticalOperations = 0;

int main()
{
    //OBS: STACK SIZE MÅSTE UTÖKAS FÖR ATT KUNNA KÖRA PROGRAMMET!
    srand((unsigned int)time(NULL));
    FILE* fptr = fopen("results.txt", "w");
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    int n[] = { 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };
    //int arr[MAX_SIZE];
    unsigned long* arrGen = (unsigned long*)malloc(sizeof(unsigned long) * MAX_SIZE);
    if (arrGen == NULL) exit(0);
    int nLen = sizeof(n) / sizeof(n[0]);




    unsigned long totalOp = 0;
    unsigned long* result = NULL;
    unsigned long avg = 0;
    unsigned long ordRes[3][8]; //[Algoritm][Array Storlek]
    unsigned long revRes[3][8]; 




    for (int i = 0; i < nLen; i++)
    {
        result = threeAlgosOneRun(arrGen, n[i], "ordered");
        ordRes[0][i] = result[0];
        ordRes[1][i] = result[1];
        ordRes[2][i] = result[2];

        result = threeAlgosOneRun(arrGen, n[i], "reverse");
        revRes[0][i] = result[0];
        revRes[1][i] = result[1];
        revRes[2][i] = result[2];
    }

    fprintf(fptr,"\n");
    fprintf(fptr,"Algoritm: Selectionsort\n");
    fprintf(fptr,"Input: Ordered\n");
    printf("\n");
    printf("Algorithm: Selectionsort\n");
    printf("Input: Ordered\n");
    for (int i = 0; i < nLen; i++)
    {
        totalOp += ordRes[0][i];
    }
    fprintf(fptr, "%lu antal op\n", totalOp);
    fprintf(fptr, "----------------\n");
    printf("%lu antal op\n", totalOp);
    printf("----------------\n");

    for (int i = 0; i < nLen; i++)
    {
        fprintf(fptr, "%lu %lu\n", n[i], ordRes[0][i]);
        printf("%lu %lu\n", n[i], ordRes[0][i]);
    }

    totalOp = 0;
    avg = 0;
    fprintf(fptr, "\n");
    fprintf(fptr, "Algoritm: Insertionsort\n");
    fprintf(fptr, "Input: Ordered\n");
    printf("\n");
    printf("Algoritm: Insertionsort\n");
    printf("Input: Ordered\n");
    for (int i = 0; i < nLen; i++)
    {
        totalOp += ordRes[1][i];
    }
    fprintf(fptr, "%lu antal op\n", totalOp);
    fprintf(fptr, "----------------\n");
    printf("%lu antal op\n", totalOp);
    printf("----------------\n");
    for (int i = 0; i < nLen; i++)
    {
        fprintf(fptr, "%lu %lu\n", n[i], ordRes[1][i]);
        printf("%lu %lu\n", n[i], ordRes[1][i]);
    }


    totalOp = 0;
    avg = 0;
    fprintf(fptr, "\n");
    fprintf(fptr, "Algoritm: Quicksort\n");
    fprintf(fptr, "Input: Ordered\n");
    printf("\n");
    printf("Algoritm: Quicksort\n");
    printf("Input: Ordered\n");
    for (int i = 0; i < nLen; i++)
    {
        totalOp += ordRes[2][i];
    }
    fprintf(fptr, "%lu antal op\n", totalOp);
    fprintf(fptr, "----------------\n");
    printf("%lu antal op\n", totalOp);
    printf("----------------\n");
    for (int i = 0; i < nLen; i++)
    {
        fprintf(fptr, "%lu %lu\n", n[i], ordRes[2][i]);
        printf("%lu %lu\n", n[i], ordRes[2][i]);
    }

    totalOp = 0;
    avg = 0;
    fprintf(fptr, "\n");
    fprintf(fptr, "Algoritm: Selectionsort\n");
    fprintf(fptr, "Input: Reverse\n");
    printf("\n");
    printf("Algoritm: Selectionsort\n");
    printf("Input: Reverse\n");
    for (int i = 0; i < nLen; i++)
    {
        totalOp += revRes[0][i];
    }
    fprintf(fptr, "%lu antal op\n", totalOp);
    fprintf(fptr, "----------------\n");
    printf("%lu antal op\n", totalOp);
    printf("----------------\n");
    for (int i = 0; i < nLen; i++)
    {
        fprintf(fptr, "%lu %lu\n", n[i], revRes[0][i]);
        printf("%lu %lu\n", n[i], revRes[0][i]);
    }

    totalOp = 0;
    avg = 0;
    fprintf(fptr, "\n");
    fprintf(fptr, "Algoritm: Insertionsort\n");
    fprintf(fptr, "Input: Reverse\n");
    printf("\n");
    printf("Algoritm: Insertionsort\n");
    printf("Input: Reverse\n");
    for (int i = 0; i < nLen; i++)
    {
        totalOp += revRes[1][i];
    }
    fprintf(fptr, "%lu antal op\n", totalOp);
    fprintf(fptr, "----------------\n");
    printf("%lu antal op\n", totalOp);
    printf("----------------\n");
    for (int i = 0; i < nLen; i++)
    {
        fprintf(fptr, "%lu %lu\n", n[i], revRes[1][i]);
        printf("%lu %lu\n", n[i], revRes[1][i]);
    }

    totalOp = 0;
    avg = 0;
    fprintf(fptr, "\n");
    fprintf(fptr, "Algoritm: Quicksort\n");
    fprintf(fptr, "Input: Reverse\n");
    printf("\n");
    printf("Algoritm: Quicksort\n");
    printf("Input: Reverse\n");
    for (int i = 0; i < nLen; i++)
    {
        totalOp += revRes[2][i];
    }
    fprintf(fptr, "%lu antal op\n", totalOp);
    fprintf(fptr, "----------------\n");
    printf("%lu antal op\n", totalOp);
    printf("----------------\n");
    for (int i = 0; i < nLen; i++)
    {
        fprintf(fptr, "%lu %lu\n", n[i], revRes[2][i]);
        printf("%lu %lu\n", n[i], revRes[2][i]);
    }

    unsigned long ranRes[3][8][30]; //[Algoritm][Array Storlek][Körning]
    unsigned long nearRes[3][8][30];
    //memset(ranRes, 0, sizeof ranRes);
    //memset(nearRes, 0, sizeof nearRes);
         

        for (int j = 0; j < 30; j++)
        {
            for (int i = 0; i < nLen; i++)
            {
                //30 runs on randomized and nearly randomized

                unsigned long* result = NULL;

                result = threeAlgosOneRun(arrGen, n[i], "random");
                ranRes[0][i][j] = result[0];
                ranRes[1][i][j] = result[1];
                ranRes[2][i][j] = result[2];
            

                result = threeAlgosOneRun(arrGen, n[i], "nearly");
                nearRes[0][i][j] = result[0];
                nearRes[1][i][j] = result[1];
                nearRes[2][i][j] = result[2];

            }                  
        }


          avg = 0;
          totalOp = 0;
          fprintf(fptr, "\n");
          fprintf(fptr, "Algoritm: Selectionsort\n");
          fprintf(fptr, "Input: Random\n");
          printf("\n");
          printf("Algoritm: Selectionsort\n");
          printf("Input: Random\n");
          for (int i = 0; i < nLen; i++)
          {
              totalOp += sumOfArray(ranRes[0][i], 30);
          }
          fprintf(fptr, "%lu antal op\n", totalOp);
          fprintf(fptr, "----------------\n");
          printf("%lu antal op\n", totalOp);
          printf("----------------\n");
          for (int i = 0; i < nLen; i++)
          {  
              avg = sumOfArray(ranRes[0][i], 30)/30; //Ran selection
              fprintf(fptr, "%lu %lu\n", n[i], avg);   
              printf("%lu %lu\n", n[i], avg);
          }

          avg = 0;
          totalOp = 0;
          fprintf(fptr, "\n");
          fprintf(fptr, "Algoritm: Insertionsort\n");
          fprintf(fptr, "Input: Random\n");
          printf("\n");
          printf("Algoritm: Insertionsort\n");
          printf("Input: Random\n");
          for (int i = 0; i < nLen; i++)
          {
              totalOp += sumOfArray(ranRes[1][i], 30);
          }
          fprintf(fptr, "%lu antal op\n", totalOp);
          fprintf(fptr, "----------------\n");
          printf("%lu antal op\n", totalOp);
          printf("----------------\n");

          for (int i = 0; i < nLen; i++)
          {
              avg = sumOfArray(ranRes[1][i], 30) / 30; //Ran selection
              fprintf(fptr, "%lu %lu\n", n[i], avg);
              printf("%lu %lu\n", n[i], avg);
          }


          avg = 0;
          totalOp = 0;
          fprintf(fptr, "\n");
          fprintf(fptr, "Algoritm: Quicksort\n");
          fprintf(fptr, "Input: Random\n");
          printf("\n");
          printf("Algoritm: Quicksort\n");
          printf("Input: Random\n");
          for (int i = 0; i < nLen; i++)
          {
              totalOp += sumOfArray(ranRes[2][i], 30);
          }
          fprintf(fptr, "%lu antal op\n", totalOp);
          fprintf(fptr, "----------------\n");
          printf("%lu antal op\n", totalOp);
          printf("----------------\n");
          for (int i = 0; i < nLen; i++)
          {
              avg = sumOfArray(ranRes[2][i], 30) / 30; //Ran selection
              fprintf(fptr, "%lu %lu\n", n[i], avg);
              printf("%lu %lu\n", n[i], avg);
          }

          //-------------------------------------------------------------------

          avg = 0;
          totalOp = 0;
          fprintf(fptr, "\n");
          fprintf(fptr, "Algoritm: Selectionsort\n");
          fprintf(fptr, "Input: Nearly Random\n");
          printf("\n");
          printf("Algoritm: Selectionsort\n");
          printf("Input: Nearly Random\n");
          for (int i = 0; i < nLen; i++)
          {
              totalOp += sumOfArray(nearRes[0][i], 30);
          }
          fprintf(fptr, "%lu antal op\n", totalOp);
          fprintf(fptr, "----------------\n");
          printf("%lu antal op\n", totalOp);
          printf("----------------\n");
          for (int i = 0; i < nLen; i++)
          {
              avg = sumOfArray(nearRes[0][i], 30) / 30; //Ran selection
              fprintf(fptr, "%lu %lu\n", n[i], avg);
              printf("%lu %lu\n", n[i], avg);
          }

          avg = 0;
          totalOp = 0;
          fprintf(fptr, "\n");
          fprintf(fptr, "Algoritm: Insertionsort\n");
          fprintf(fptr, "Input: Nearly Random\n");
          printf("\n");
          printf("Algoritm: Insertionsort\n");
          printf("Input: Nearly Random\n");
          
          for (int i = 0; i < nLen; i++)
          {
              totalOp += sumOfArray(nearRes[1][i], 30);
          }
        
          fprintf(fptr, "%lu antal op\n", totalOp);
          fprintf(fptr, "----------------\n");
          printf("%lu antal op\n", totalOp);
          printf("----------------\n");

          for (int i = 0; i < nLen; i++)
          {
              avg = sumOfArray(nearRes[1][i], 30) / 30; //Ran selection
              fprintf(fptr, "%lu %lu\n", n[i], avg);
              printf("%lu %lu\n", n[i], avg);
          }


          avg = 0;
          totalOp = 0;
          fprintf(fptr, "\n");
          fprintf(fptr, "Algoritm: Quicksort\n");
          fprintf(fptr, "Input: Nearly Random\n");
          printf("\n");
          printf("Algoritm: Quicksort\n");
          printf("Input: Nearly Random\n");

          for (int i = 0; i < nLen; i++)
          {
              totalOp += sumOfArray(nearRes[2][i], 30);
          }

          fprintf(fptr, "%lu antal op\n", totalOp);
          fprintf(fptr, "----------------\n");
          printf("%lu antal op\n", totalOp);
          printf("----------------\n");

          for (int i = 0; i < nLen; i++)
          {
              avg = sumOfArray(nearRes[2][i], 30) / 30; //Ran selection
              fprintf(fptr, "%lu %lu\n", n[i], avg);
              printf("%lu %lu\n", n[i], avg);
          }

          fclose(fptr);

}


unsigned long sumOfArray(unsigned long a[], unsigned long len)
{

    unsigned long sum = 0;
    for (unsigned long i = 0; i < len; i++)
    {
        sum += a[i];
    }
    return sum;
}

void copyArray(unsigned long arr[], unsigned long copy[], int size)
{
    // loop to iterate through array
    for (int i = 0; i < size; ++i)
    {
        copy[i] = arr[i];
    }
}

unsigned long* threeAlgosOneRun(unsigned long arrGen[], int length, const char* type)
{
    unsigned long* arrRes = (unsigned long*)malloc(sizeof(unsigned long) * MAX_SIZE);
    if (arrRes == NULL) exit(0);

    unsigned long* result = (unsigned long*)malloc(sizeof(unsigned long) * 3);
    if (result == NULL) exit(0);
    
    generate_input(arrGen, length, type);

    criticalOperations = 0;
    copyArray(arrGen, arrRes, length);
    selectionSort(arrRes, length, &criticalOperations);
    result[0] = criticalOperations;

    criticalOperations = 0;
    copyArray(arrGen, arrRes, length);
    insertionSort(arrRes, length, &criticalOperations);
    result[1] = criticalOperations;

    criticalOperations = 0;
    copyArray(arrGen, arrRes, length);

    quicksort(arrGen, 0, length-1, &criticalOperations);
    result[2] = criticalOperations;

    return result;
}