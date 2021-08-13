/**
 * Program to implement merge sort on an array of integers using recursion.
 * Compilation: gcc -o merge_sort merge_sort.c
 * Execution:   ./merge_sort
 *
 * @Aanchal, 1910990158, 13/8/2021
 */

#include <stdio.h>

// Function to merge the two subarrays  ---> from left to mid, from mid+1 to right
void merge(int a[], int l, int mid, int r, int b[])
{
    
    int i = l;
    int j = mid+1;
    int k = l;

    while(k <= r)
    {
        if(i > mid)  // // after placing all the elements of left subarray....add remaining elements of right subarray
            b[k++] = a[j++];

        else if(j > r)  // after placing all the elements of right subarray....add remaining elements of left subarray
            b[k++] = a[i++];

        else if(a[i] > a[j])
            b[k++] = a[j++];

        else
            b[k++] = a[i++];

    }
 
    for(k = l; k <= r; k++)
    {
        a[k] = b[k];
    }
    
}

// Function to recursively split array into 2 subparts and merge
void merge_sort(int a[], int l, int r, int b[])
{
    // Base Condition
    if (l == r)        // size of subarray == 1
        return;
    
    int mid = (l + r) / 2;
    
    merge_sort(a, l, mid, b);    // Left subarray
    merge_sort(a, mid+1, r, b);  // Right subarray

    merge(a, l, mid, r, b);// Merge subarrays using b[] array
}

int main()
{
    int size;
    scanf("%d",&size);
    int a[size], b[size];  // a[] : Input Array;  b[]: Aux Array

    for(int i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
        b[i] = a[i];
    }

    merge_sort(a, 0, size - 1, b);

    for(int i = 0; i < size; i++)
        printf("%d ",a[i]);

    return 0;
}
