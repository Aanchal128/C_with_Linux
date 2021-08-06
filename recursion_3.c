/**
 * Program to implement the tower of hanoi function using Recursion.
 * Compilation: gcc -o recursion_3  recursion_3.c
 * Execution:   ./recursion_3
 *
 * Assignment_5 - Recursion
 * @Aanchal, 1910990158, 6/8/2021
 */

#include <stdio.h>

int count = 0;
// Prints the movement of disk along with count of movements
void tower_of_hanoi(int n, char from, char to, char aux)
{   
    if (n <= 1)
    {
        printf("%c to %c\n", from, to);
        count++;
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    printf("%c to %c\n", from, to);
    count++;
    tower_of_hanoi(n - 1, aux, to, from);
}

int main()
{
    tower_of_hanoi(3,'A','C','B');
    printf("Total movements required = %d",count);
}

