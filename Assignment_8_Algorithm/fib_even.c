/**
 * Program to print n numbers in Fibonacci series that are even
 * Compilation: gcc -o fib_even fib_even.c
 * Execution:   ./fib_even
 *
 * Assignment 8 - Algorithm
 * @Aanchal, 1910990158, 20/8/2021
 */


// Base Case: f1 = 1, f2 = 1
// f3 = 2
// f4 = f3 + f2  as f3 is even and f2 is odd --> f4 is odd....similarly f5 is odd
// Every 3rd element in fibonacci series is even

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int f3 = 2;
    int f6 = 8;

    for(int k = 0; k < n; k++)
    {
        printf("%d\n", f3);
        int temp = f3;
        f3 = f6;
        f6 = 4*f3 + temp;

    }
}
