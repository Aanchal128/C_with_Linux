/**
 * Program to analyze time complexity of Bubble Sort.
 * Calculates time to bubble sort using gettimeoftheday function.
 * Compilation: gcc -o bubble_sort  bubble_sort.c
 * Execution:   ./bubble_sort
 *
 * @Aanchal, 1910990158, 26/7/2021
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
 
    for( int pass = 0; pass < size-1; pass++)
    {
        int sw = 0;
        for( int curr = 0; curr < size-1-pass; curr++)
        {
            if(a[curr] > a[curr+1])
            {
                swap(a,curr,curr+1);
                sw = 1;
            }
        }
 
        if(sw==0)
        {
            break;
        }
    }

    //end time
    gettimeofday(&t, NULL);
    long long end = t.tv_sec*1000 + t.tv_usec/1000;

    printf("%lld\n",end - start);

}
