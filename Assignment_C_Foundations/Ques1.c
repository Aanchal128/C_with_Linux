/**
 * Program to swap two numbers without using a third variable.
 * Compilation: gcc -o Ques_1  Ques_1.c
 * Execution:   ./Ques_1
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include<stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Input:\na = %d, b = %d\n", a, b);

    a = a + b;   
    b = a - b;  
    a = a - b;

    printf("\nOutput:\na = %d, b = %d", a, b);
    return 0;
}
