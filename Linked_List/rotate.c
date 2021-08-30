/**
 * "https://leetcode.com/problems/rotate-list/"
 * Compilation: gcc -o rotate rotate.c
 * Execution: ./rotate
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


struct ListNode* rotateRight(struct ListNode* head, int k)
{
    // Edge cases
    if(k == 0 || head == NULL || head->next == NULL)
        return head;
    
    struct ListNode *ptr = head;
    int s = 1;
    // find length
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        s++;
    }
    
    // if k is multiple of length
    if(k % s == 0)
        return head;
    
    if(k > s)
        k = k % s;
    
    s--;
    
    // create a cycle (link end to head)
    ptr->next = head;
    
    struct ListNode *ptr2 = head;
    int c = 0;
    
    // traverse to node before kth node from end
    while(c < s-k)
    {
        ptr2 = ptr2->next;
        c++;
    }
    
    // store kth node from end and break the link
    ptr = ptr2->next;
    ptr2->next = NULL;
    head = ptr;
    
    return head;
}
