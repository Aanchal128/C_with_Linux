/**
 * Program to implement Queue using array.
 * Compilation: gcc -o queue queue.c
 * Execution: ./queue
 * 
 * @Aanchal, 1910990158, 2/08/2021
 */

#include <stdio.h>

int a[6];
int head = -1, tail = -1;

// To check whether queue is empty or not
// Return 1 if the queue is empty, else return 0
int is_empty()
{
    if(head == -1 || head > tail)
        return 1;
    return 0;
}

// To add a new element to the tail of the queue
void enqueue(int value)
{
    if(head == -1)
    {
        head = 0;
        tail += 1;
        a[tail] = value;
    }
    else if(tail < 6 && head > -1)
    {
        tail += 1;
        a[tail] = value;
    }
    else
        printf("Overflow\n");

}

// Remove and return the element at the head of the queue
int dequeue()
{
    if(!is_empty())
    {
        int el = a[head];
        head += 1;
        return el;
    }
    else
        return -1;
}

// Return but not remove the element at the head of the queue
int peek()
{
    if(!is_empty())
        return a[head];
    else
        return -1;
}

int main()
{
    enqueue(1);
    enqueue(2);
    printf("%d\n",peek()); // Output: 1
    enqueue(3);
    enqueue(4);
    printf("%d\n",dequeue());  // Output: 1
    printf("%d\n",peek());     // Output: 2
    printf("%d\n",dequeue());  // Output: 2
    printf("%d\n",peek());     // Output: 3
    return 0;
}
