/**
 * Program to analyze time complexity of Selection Sort using gettimeoftheday function.
 * Compilation: gcc -o selection_sort  selection_sort.c
 * Execution:   ./selection_sort
 *
 * Link to Excel sheet: "https://docs.google.com/spreadsheets/d/1fGhS8wUM-cQo5U9mC_e8Yn6WfkB8GNbxPfq2DbiH98k/edit?usp=sharing"
 *
 * @Aanchal, 1910990158, 31/7/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(int a[], int j, int k)
{
    int temp;
    temp = a[j];
    a[j] = a[k];
    a[k] = temp;
}

int main()
{
    int size;
    scanf("%d",&size);
    int a[size];

    int i, j;
    for(i = 0; i < size; i++)
    {
        //for random data
        a[i] = rand();

        //for data in ascending order  
        //a[i] = i;

        //for data in descending order
        //a[i] = size - i;

    }

    struct timeval t;
    gettimeofday(&t, NULL);
    // start time
    long long start = t.tv_sec*1000 + t.tv_usec/1000;

    for(i = 0; i < size-1; i++)
    {   
        int min = i;
        // find the min element in the array
        for(j = i+1; j < size; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        
        // swap only if min is other element than assumed
        if(min != i)
        {
            swap(a,min,i);
        }
    }

    //end time
    gettimeofday(&t, NULL);
    long long end = t.tv_sec*1000 + t.tv_usec/1000;

    printf("%lld",end - start);

}
