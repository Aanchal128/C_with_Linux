/**
 * "https://leetcode.com/problems/merge-two-sorted-lists/"
 * Compilation: gcc -o merge merge.c
 * Execution: ./merge
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

int compare(int a, int b)
{
    if(a <= b)
        return a;
    else
        return b;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    // Edge cases
    if(l1 == NULL && l2 == NULL)
        return l1;
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    
    struct ListNode* l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l3 = NULL;
    struct ListNode* ptr = l3;
    
    while(l1 != NULL && l2 != NULL)
    {
        // compare
        int value = compare(l1->val, l2->val);
        struct ListNode* temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = value;
        temp->next = NULL;
        
        // Insert at head
        if(l3 == NULL)
        {    
            l3 = temp;
            ptr = l3;
        }
        else
        {
            ptr->next = temp;
            ptr = ptr->next;
        }
            
        if(value == l2->val)
            l2 = l2->next;
        else
            l1 = l1->next;
    }
    
    // add remaining
    if(l2 != NULL)
    {
        while(l2 != NULL)
        {
            ptr->next = l2;
            l2 = l2->next;
            ptr = ptr->next;
        }
    }
    
    
    else if(l1 != NULL)
    {
        while(l1 != NULL)
        {
            ptr->next = l1;
            l1 = l1->next;
            ptr = ptr->next;
        }
    }
    
    return l3;

}
