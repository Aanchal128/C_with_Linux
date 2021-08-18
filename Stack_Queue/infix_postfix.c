/**
 * Program to convert an arithmetic expression from infix notation
to postfix notation.
 * Compilation: gcc -o ip infix_postfix.c
 * Execution: ./ip
 * 
 * Assignment 4 - Stacks and Queues
 * @Aanchal, 1910990158, 18/08/2021
 */

#include <stdio.h>

char a[20];
int top = -1;

void push(char value)
{
    if(top < 19)
    {
        top += 1;
        a[top] = value;
    }
    else
        printf("Overflow\n");

}

char pop()
{
    if(top > -1)
    {
        char el = a[top];
        top -= 1;
        return el;
    }
    else
        return -1;
}

char peek()
{
    if(top > -1)
        return a[top];
    else
        return -1;
}

void postfix(char* s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        char el = s[i];
        if(el == '(' || el == '+' || el == '-' || el == '*' || el == '/')
        {
            push(el);
        }
        else if(el >= '0' && el <= '9')
        {
            printf("%c ",el);
        }
        else
        {
            printf("%c ",pop());
            pop();
        }
        i++;
    }
    return ;
    
}
int main()
{
    char s[] = "1+2*3-(4/5+6*7*8)";

    postfix(s);
    return 0;
}

