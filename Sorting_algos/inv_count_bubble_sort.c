/**
 * Program to find inversion count of an array of integers.
 * Compilation: gcc -o inv_count_bubble_sort inv_count_bubble_sort.c
 * Execution:   ./inv_count_bubble_sort
 *
 * Assignment_7 - Sorting
 * @Aanchal, 1910990158, 13/8/2021
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
    for(i = 0; i < size; i++)
        scanf("%d",&a[i]);
    
    int inv_count = 0, sw;
    // for size-1 passes
    for( int pass = 0; pass < size-1; pass++)
    {
        sw = 0;
        for( int curr = 0; curr < size-1-pass; curr++)
        {   // if current element is greater than its adjacent element -> swap
            if(a[curr] > a[curr+1])
            {
                swap(a,curr,curr+1);
                sw += 1;
            }
        }
        // Inversion Count: Number of swaps needed to sort the array
        inv_count += sw; 
        
        // no swaps -> array is already sorted
        if(sw==0)
            break;
    }
    
    printf("%d",inv_count);
    return 0;
}

