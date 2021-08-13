/**
 * Program to implement Stack using array.
 * Compilation: gcc -o stack stack.c
 * Execution: ./stack
 * 
 * @Aanchal, 1910990158, 2/08/2021
 */
#include <stdio.h>

int stack[6];
int top = -1;

// To check if the stack is empty or not
// Return 1 if the stack is empty, else return 0
int is_empty()
{
    if(top == -1)
        return 1;
    return 0;
}

// To add a new element to the top of the stack
void push(int value)
{
    if(top < 6)
    {
        top += 1;
        stack[top] = value;
    }
    else
        printf("Overflow\n");

}

// Removes and returns the element from the top of the stack
int pop()
{
    if(!is_empty())
    {
        int el = stack[top];
        top -= 1;
        return el;
    }
    else
        return -1;
}

// Return but not remove the element at the top of the stack
int peek()
{
    if(!is_empty())
        return stack[top];
    else
        return -1;
}

int main()
{
    push(1);
    push(2);
    push(3);
    printf("%d\n",peek());  // --> Output: 3
    push(4);
    push(5);
    printf("%d\n",pop());  // --> Output: 5
    printf("%d\n",peek()); // --> Output: 4

    return 0;
}
