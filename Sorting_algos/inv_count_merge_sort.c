/**
 * Program to find inversion count of an array of integers.
 * Compilation: gcc -o inv_count_merge_sort inv_count_merge_sort.c
 * Execution:   ./inv_count_merge_sort
 *
 * Assignment_7 - Sorting
 * @Aanchal, 1910990158, 13/8/2021
 */

#include <stdio.h>

int inv_count = 0;

// Function to merge the two subarrays  ---> from left to mid, from mid+1 to right
void merge(int a[], int l, int mid, int r, int b[])
{
    
    int i = l;
    int j = mid+1;
    int k = l;

    while(k <= r)
    {
        if(i > mid)  // // after placing all the elements of left subarray....add remaining elements of right subarray
        {
            b[k++] = a[j++];
        }
        else if(j > r)  // after placing all the elements of right subarray....add remaining elements of left subarray
        {
            b[k++] = a[i++];
        }
        else if(a[i] > a[j])
        {
            b[k++] = a[j++];
            inv_count += mid-i+1; // count of inversions from ith element till the mid element
        }
        else
        {
            b[k++] = a[i++];
        }
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
    printf("%d",inv_count);
    return 0;
}
