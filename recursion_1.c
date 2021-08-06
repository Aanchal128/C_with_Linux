/**
 * Program to implement Selection Sort using Recursion.
 * Compilation: gcc -o recursion_1  recursion_1.c
 * Execution:   ./recursion_1
 *
 * Assignment_5 - Recursion
 * @Aanchal, 1910990158, 6/8/2021
 */

#include <stdio.h>

void swap(int a[], int j, int k)
{
    int temp;
    temp = a[j];
    a[j] = a[k];
    a[k] = temp;
}

/* Finds the max element in the array and places it at the end.
 *
 * Parameters
 * a[]: array of integers
 * end: Last element of the array
 * Returns the array in sorted order
 */
void selection_sort(int a[], int end)
{   
    // Base Condition
    if(end < 0)
        return ;

    int max = end;
    // find the max element in the array
    for(int j = 0; j < end; j++)
    {
        if(a[j] > a[max])
            max = j;
    }
        
    // swap only if max is other element than assumed
    if(max != end)
        swap(a, max, end);

    selection_sort(a, end-1);  
}

int main()
{
    // Input
    int size;
    scanf("%d",&size);
    int a[size];
    int i;
    for(i = 0; i < size; i++)
        scanf("%d",&a[i]);
    
    selection_sort(a, size-1);

    // Output
    for(i = 0; i < size; i++)
        printf("%d ",a[i]);
}
