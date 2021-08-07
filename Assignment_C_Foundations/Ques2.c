/**
 * Program to print a pyramid having a given number of steps.
 * Compilation: gcc -o Ques_2  Ques_2.c
 * Execution:   ./Ques_2
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include<stdio.h>
int main()
{
    int i, j, k, steps;
    scanf("%d",&steps);

    for(i = 1; i <= steps; i++)
    {
        for(j = i; j < steps; j++)
            printf(" ");
        for(k = 1; k <= i; k++)
            printf("# ");
        printf("\n");
    }
    return 0;
}
