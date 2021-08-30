/**
 * Program to implement Queue using doubly linked list.
 * Compilation: gcc -o deque_ll deque_ll.c
 * Execution: ./deque_ll
 * 
 * Assignment_6 - Linked List
 * @Aanchal, 1910990158, 30/08/2021
 */

#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

// Add a new element to the head of the deque
void enqueueHead(int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    // If deque is empty
    if (head == NULL)
        tail = head = temp;
 
    // Insert node at the front end
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

}

// Add a new element to the tail of the deque
void enqueueTail(int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    
    // If deque is empty
    if (tail == NULL)
        head = tail = temp;
 
    // Insert node at the rear end
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }

}

// Check whether deque is empty or not
// Return 1 if deque is empty, else return 0
int isEmpty()
{
    if(head == NULL)
        return 1;
    return 0;
}

// Remove and return the element from the head of deque
int dequeueHead()
{
    if (isEmpty())
    {
        printf("UnderFlow\n");
        return -1;
    }
    else
    {
        int val = head->data;
        head = head->next;
 
        // If only one element was present
        if (head == NULL)
            tail = NULL;
        else
            head->prev = NULL;
        return val;
    }
}

// Remove and return the element from the tail of deque
int dequeueTail()
{
    if (isEmpty())
    {
        printf("UnderFlow\n");
        return -1;
    }
    else
    {
        int val = tail->data;
        tail = tail->prev;
 
        // If only one element was present
        if (tail == NULL)
            head = NULL;
        else
            tail->next = NULL;
        return val;
    }
}

// Return but not remove the element at the head of deque
int peekHead()
{
    if (isEmpty())
        return -1;
    return head->data;
}

// Return but not remove the element at the tail of deque
int peekTail()
{
    if (isEmpty())
        return -1;
    return tail->data;
}

// Check if given element is present in deque or not
int is_present(int val) 
{
    struct Node* temp = head;
    
    while(temp != NULL) 
    {
        if(temp->data == val) 
            return 1;
        temp = temp->next;
    }
    
    return 0;
}

int main()
{
    enqueueHead(1);
    enqueueHead(2);
    printf("%d\n",peekHead()); // Output: 2

    enqueueTail(4);
    enqueueTail(5);
    // 2->1->4->5
    printf("%d\n",is_present(2));
    printf("%d\n",peekTail());  // Output: 5
    
    printf("%d\n",dequeueHead()); // Output: 2
    printf("%d\n",peekHead());    // Output: 1

    printf("%d\n",dequeueTail());  // Output: 5
    printf("%d\n",peekTail());     // Output: 4
    
    return 0;
}
