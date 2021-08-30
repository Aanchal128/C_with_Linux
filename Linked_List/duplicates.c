/**
 * "https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/"
 * Compilation: gcc -o duplicates duplicates.c
 * Execution: ./duplicates
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

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    // Edge cases
    if(head == NULL || head->next == NULL)
        return head;
    
    // to delete all same nodes ---> start from prev node
    // find next non-repeating node
    // prev->next = non-repeating node
    
    // [1,1,1,2,3]  ---> head is repeating
    // start 1 step behind head 
    struct ListNode* prev = (struct ListNode*)malloc(sizeof(struct ListNode));
    prev->next = head;
    
    struct ListNode* curr = prev->next;
    
    while(curr != NULL)
    {
        if(curr->next != NULL && curr->next->val == curr->val)
        {
            while(curr->next != NULL && curr->val == curr->next->val)
                curr = curr->next;
            if(head->val == curr->val)
                head = curr->next;
            curr = curr->next;
            
        }
        
        else
        {
            prev->next = curr;
            prev = curr;
            curr = curr->next;
        }
    }
    
    prev->next = curr;
    
    return head;

}
