/**
 * Program to implement Queue using linked list.
 * Compilation: gcc -o queue_ll queue_ll.c
 * Execution: ./queue_ll
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

struct Node *head = NULL, *tail = NULL;

// Add a new element to the tail of the queue
void enqueueTail(int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    // If queue is empty
    if (tail == NULL)
        head = tail = temp;
 
    // Inserts node at the rear end
    else
    {
        tail->next = temp;
        tail = temp;
    }

}

// Check whether queue is empty or not
// Return 1 if the queue is empty, else return 0
int isEmpty()
{
    if(head == NULL)
        return 1;
    return 0;
}

// Remove and return the element at the head of the queue
int dequeueHead()
{
    if (isEmpty(head))
    {
        printf("UnderFlow\n"); 
        return -1;
    }
    
    else
    {
        int val = head->data;
        head = head->next;
        
        if (head == NULL)
            tail = NULL;

        return val;
    }
}

// Return but not remove the element at the head of the queue
int peek()
{
    if (isEmpty(head))
        return -1;
    return head->data;
}

int main()
{
    enqueueTail(4);
    enqueueTail(5);
    printf("%d\n",peek());  // Output: 4
    
    enqueueTail(7);

    printf("%d\n",dequeueHead()); // Output: 4
    printf("%d\n",dequeueHead()); // Output: 5
    printf("%d\n",peek());        // Output: 7

    return 0;
}
