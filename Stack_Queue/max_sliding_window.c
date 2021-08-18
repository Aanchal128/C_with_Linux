/**
 * Program to find the maximum element in every window of a given size in an array (using a deque)
 * Compilation: gcc -o msw max_sliding_window.c
 * Execution: ./msw
 *
 * LeetCode : "https://leetcode.com/problems/sliding-window-maximum/" 
 * Assignment 4 - Stacks and Queues
 * @Aanchal, 1910990158, 18/08/2021
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
    int pos;
};

int isEmpty(struct Node *h)
{
    if(h == NULL)
        return 1;
    return 0;
}

// Remove an element from head of deque
void dequeueHead(struct Node **h, struct Node **t)
{
    struct Node* temp = (*h);
    (*h) = (*h)->next;
 
        // If only one element was present
    if ((*h) == NULL)
        (*t) = NULL;
    else
        (*h)->prev = NULL;
    free(temp);
}

// Remove an element from tail of deque
void dequeueTail(struct Node **h, struct Node **t)
{
    struct Node* temp = (*t);
    (*t) = (*t)->prev;
 
    // If only one element was present
    if ((*t) == NULL)
        (*h) = NULL;
    else
        (*t)->next = NULL;
    free(temp);
}

// To add an element at the tail of deque
void enqueue(struct Node **h, struct Node **t, int value, int p)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    temp->pos = p;

    // If deque is empty
    if ((*t) == NULL)
        (*h) = (*t) = temp;
        
    // if temp is greater than element at tail
    // remove elements from tail until an element greater to temp is reached
    // max is always at front of deque 
    else
    {
        if(temp->data > (*t)->data)
        {
            dequeueTail(h, t);
            enqueue(h, t, temp->data, p);
        }
        else
        {
            temp->prev = (*t);
            (*t)->next = temp;
            (*t) = temp;
        }
        
    }

}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    int len = numsSize - (k-1);
    int* max = malloc(sizeof(int) * len);
    *returnSize = len;
    
    // Edge Case
    if(numsSize == 1 && k == 1)
    {
        max[0] = nums[0];
        return max;
    }
    
    struct Node *head = NULL, *tail = NULL;
    
    // First window
    int i = 0;
    for(i = 0; i < k; i++)
    {
        enqueue(&head, &tail, nums[i], i);
    }
    
    max[0] = head->data;
    
    if(numsSize > k)
    {   // i = k ---> window -->from i till i+k-1
        // if element at head of deque is not in window --> remove that element
        if((head->pos) == i-k)
            dequeueHead(&head, &tail);
        
        int j = 1;
        for(i = k; i < numsSize; i++)
        {   
            enqueue(&head, &tail, nums[i], i);

            max[j] = head->data;
            j++;
            
            if((head->pos) == i-k+1)
                dequeueHead(&head, &tail);
        }
    }
    
    return max;
}
