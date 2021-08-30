/**
 * "https://leetcode.com/problems/remove-nth-node-from-end-of-list/"
 * Compilation: gcc -o remove nth_from_end.c
 * Execution: ./remove
 * 
 * Assignment_6 - Linked List
 * @Aanchal, 1910990158, 30/08/2021
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
     // Edge cases
    if(head->next == NULL && n == 1)
        return NULL;
    if(head->next->next == NULL && n == 1)
    {
        head->next = NULL;
        return head;
    }
      
    if(head->next->next == NULL && n == 2)
        return head->next;
    
    // Maintain two pointers and update one with a delay of n steps
    
    struct ListNode* ptr = head;
    struct ListNode* n_ahead = head;
    
    // delay of n-1 steps
    while(n > 0)
    {
        n_ahead = n_ahead->next;
        n--;
    }
    
    // if nth node from end is head node
    if(n_ahead == NULL)
        return head->next;
    
    n_ahead = n_ahead->next;
    while(n_ahead != NULL) {
        n_ahead = n_ahead->next;
        ptr = ptr->next;
    }
    
    // ptr is now at (n+1)th node from last
    ptr->next = ptr->next->next;
    
    return head;
}

