/**
 * Program to find GCD of 2 numbers using Recursion.
 * Compilation: gcc -o recursion_2  recursion_2.c
 * Execution:   ./recursion_2
 *
 * Assignment_5 - Recursion
 * @Aanchal, 1910990158, 6/8/2021
 */

#include <stdio.h>

int gcd(int a, int b)
{
    if(a == b)
        return a;
    if(a % b == 0)
        return b;
    if(b % a == 0)
        return a;
    if(a > b)
        return (gcd(a % b, b));
    else
        return (gcd(a, b % a));
}

int main()
{
    // Input
    int a, b;
    scanf("%d %d",&a,&b);

    // Output
    printf("%d",gcd(a, b));
}
