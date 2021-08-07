/**
 * Program to reverse the given 1 D array
 * Compilation: gcc -o Ques_4  Ques_4.c
 * Execution:   ./Ques_4
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include <stdio.h>

// Function to reverse 1 D array
void reverse(int *a, int n)
{
    int i = 0, j = n - 1;
    // Swapping elements at front end with elements at rear end
    while(i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}

int main()
{   
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i = 0; i < size; i++)
        scanf("%d",&arr[i]);

    reverse(arr, size);

    for(int i = 0; i < size; i++)
        printf("%d ",arr[i]);

    return 0;
}
