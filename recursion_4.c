/**
 * Program to print n times the every third element of fibonacci series using recursion with memoization.
 * Compilation: gcc -o recursion_4  recursion_4.c
 * Execution:   ./recursion_4
 *
 * Assignment_5 - Recursion
 * @Aanchal, 1910990158, 6/8/2021
 */

#include<stdio.h>

// Array to store the value of function calls
int a[19];


int fib(int n)
{
    // If value of the function call is already stored in the array
    if(a[n] != -1)
        return a[n];

    // else store it
    a[n] = fib(n-1) + fib(n-2);
    return a[n];
} 
 
int main()
{   
    // Base condition: fib(0) = 0, fib(1) = 1
    a[0] = 0;
    a[1] = 1;

    // Initializing every element of the array as -1
    for(int i = 2; i < 19; i++)
        a[i] = -1;
    
    int n, c;
    scanf("%d",&n);

    // to print n times the every third element
    // n = 5 : 2 8 34 144 610
    printf("Fibonacci series\n");
    for( c = 3 ; c <= n*3 ; c += 3 )
    {
      printf("%d ", fib(c));
    } 
   return 0;
}

