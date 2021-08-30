/**
 * Program to implement Stack using linked list.
 * Compilation: gcc -o stack_ll stack_ll.c
 * Execution: ./stack_ll
 *
 * Assignment_6 - Linked List 
 * @Aanchal, 1910990158, 30/08/2021
 */

#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};

struct Node* top = NULL;

// Add a new element to the top of the stack
void push(int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if (top == NULL)
        top = temp;
 
    else
    {
        temp->next = top;
        top = temp;
    }

}

// Check if the stack is empty or not
// Return 1 if the stack is empty, else return 0
int isEmpty()
{
    if(top == NULL)
        return 1;
    return 0;
}

// Remove and return the element from the top of the stack
int pop()
{
    if (isEmpty(top))
    {    
        printf("UnderFlow\n");
        return -1;
    }
    else
    {
        int val = top->data;
        top = top->next;
        return val;
    }
}

// Return but not remove the element at the top of the stack
int peek()
{
    if (isEmpty(top))
        return -1;
    return top->data;
}

int main()
{
    push(4);
    push(5);
    printf("%d\n",peek()); // Output: 5

    push(7);
    printf("%d\n",peek()); // Output: 7

    printf("%d\n",pop());  // Output: 7
    printf("%d\n",pop());  // Output: 5
    printf("%d\n",peek()); // Output: 4
    printf("%d\n",pop());
    printf("%d\n",pop()); // UnderFlow
    
    return 0;
}
