/**
 * Program to find Mth smallest number in an unsorted array
 * Compilation: gcc -o mth_smallest mth_smallest.c
 * Execution:   ./mth_smallest
 *
 * Assignment 8 - Algorithm
 * @Aanchal, 1910990158, 20/8/2021
 */

#include <stdio.h>

void swap(int a[], int j, int k)
{
    int temp;
    temp = a[j];
    a[j] = a[k];
    a[k] = temp;
}

int mth_smallest(int a[], int l, int r, int m)
{
    // exit condition : only 1 element
    if(l==r)
        return a[l];
    
    // random number between l and r
    int p = (rand() % (r-l+1)) + l;
    swap(a,p,l);
    // p -> Pivot, f-> Final position of p
    p = l;
    int f = l;

    printf("PIVOT %d\n",a[p]);
    for(int i = l+1;i <= r; i++)
    {
        if(a[i] < a[p])
        {
            printf("SWAPPING %d with %d\n",a[i],a[f+1]);
            swap(a, i, ++f);
        }
            
    }

    printf("CORRECT POSITION of PIVOT %d\n",f);
    swap(a, p, f);

    // if mth smallest is at final index of pivot ---> return pivot element
    if (f == m - 1)
            return a[f];
    
    //if index of mth smallest is less than final index of pivot--->check left
    if (f > m - 1)
    {
        printf("\nLeft side of Pivot\n");
        return mth_smallest(a, l, f-1, m);
    }

    // else check right
    printf("\nRight side of Pivot\n");
    mth_smallest(a, f+1, r, m);

}

int main()
{ 
    int a[] = {15,7,1,4,2,9};
    printf("%d\n",mth_smallest(a, 0, 5, 3)); // OUTPUT: 4

    return 0;
}
