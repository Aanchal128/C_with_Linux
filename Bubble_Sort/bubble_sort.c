/**
 * Program to implement Bubble Sort.
 * Compilation: gcc -o bubble_sort  bubble_sort.c
 * Execution:   ./bubble_sort
 *
 * @Aanchal, 1910990158, 26/7/2021
 */

#include <stdio.h>

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
    // Input
    for(i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);

    }
    
    // for size-1 passes
    for( int pass = 0; pass < size-1; pass++)
    {
        int sw = 0;
        for( int curr = 0; curr < size-1-pass; curr++)
        {   // if current element is greater than its adjacent element -> swap
            if(a[curr] > a[curr+1])
            {
                swap(a,curr,curr+1);
                sw = 1;
            }
        }
        // no elements are swapped -> array is already sorted
        if(sw==0)
        {
            break;
        }
    }
    
    // Output
    for(i = 0; i < size; i++)
        printf("%d ",a[i]);

    return 0;
}
