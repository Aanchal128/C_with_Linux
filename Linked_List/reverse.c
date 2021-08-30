/**
 * "https://leetcode.com/problems/reverse-linked-list-ii/"
 * Compilation: gcc -o reverse reverse.c
 * Execution: ./reverse
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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    // Edge Cases
    if(head->next == NULL || left == right)
        return head;
    
    if(left == 1 && right == 2)
    {
        struct ListNode *temp = head;
        struct ListNode *temp2 = head->next->next;
        head = head->next;
        head->next = temp;
        temp->next = temp2;
        return head;
    }

    struct ListNode *L = head;
    struct ListNode *beforeL = head;
    if(left > 1)
    {
        int cl = 1;
        while(cl < left)
        {
            beforeL = L;
            L = L->next;
            cl++;
        }
    }
    
    struct ListNode *prev = NULL;
    struct ListNode *curr = NULL;
    struct ListNode *after = NULL;

    if(left == 1)
        curr = head;
    
    else
        curr = L;

    while(right-left >= 0)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
        right--;
    }
    
    if(left == 1)
    {
        head->next = after;
        head = prev;
    }
        
    else
    {
        L->next = after;
        L = prev;
        beforeL->next = L;
    }
    
    return head;
    
}
