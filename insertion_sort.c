/**
 * Program to analyze time complexity of Insertion Sort using gettimeoftheday function.
 * Compilation: gcc -o insertion_sort  insertion_sort.c
 * Execution:   ./insertion_sort
 *
 * Link to Excel sheet: "https://docs.google.com/spreadsheets/d/1fGhS8wUM-cQo5U9mC_e8Yn6WfkB8GNbxPfq2DbiH98k/edit?usp=sharing"
 *
 * @Aanchal, 1910990158, 31/7/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
    int size;
    scanf("%d",&size);
    int a[size];

    int i;
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

    for(i = 1; i < size; i++)
    {   // Considering element at 0th index is at correct position
        int curr = a[i];
        int prev = i - 1;

        // Check if current element is at the correct position; if not shift previous elements
        while(prev >= 0 && a[prev] > curr)
        {
            a[prev+1] = a[prev];
            prev--;    
        }
        a[prev+1] = curr;

    }

    //end time
    gettimeofday(&t, NULL);
    long long end = t.tv_sec*1000 + t.tv_usec/1000;

    printf("%lld",end - start);

}
