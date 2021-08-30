/**
 * "https://leetcode.com/problems/palindrome-linked-list/"
 * Compilation: gcc -o palindrome palindrome.c
 * Execution: ./palindrome
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

// To reverse the linked list
struct ListNode * reverse(struct ListNode* p)
{
    struct ListNode *prev = NULL;
    struct ListNode *curr = NULL;
    struct ListNode *after = NULL;

    curr = p;

    while(curr != NULL)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    p = prev;
    
    return p;
}

bool isPalindrome(struct ListNode* head)
{
    // Edge case 0 nodes
    if(head == NULL)
        return false;
    
    // Edge case 1
    if(head->next == NULL)
        return true;
    
    // Edge case 2
    if(head->next->next == NULL)
    {
        if(head->val == head->next->val)
            return true;
        return false;
    }
    
    // Edge case 3
    if(head->next->next->next == NULL)
    {
        if(head->val == head->next->next->val)
            return true;
        return false;
    }
    
    // when elements start repeating....reverse remaining linked list
    struct ListNode* ptr = head;
    struct ListNode* half = NULL;
    
    while(ptr->next != NULL)
    {
        if(ptr->next->next != NULL)
        {
            if(ptr->val == ptr->next->val)
            {
                half = reverse(ptr->next);
                break;
            }
            else if(ptr->val == ptr->next->next->val)
            {
                half = reverse(ptr->next);
                break;
            }
        }
        
        ptr = ptr->next;
    }
    
    if(half == NULL)
        return false;
    
    // check if reversed half is same as front half
    while(half != NULL && head != NULL)
    {
        if(head->val == half->val)
        {
            head = head->next;
            half = half->next;
        }
        else
            return false;
    }
    return true;

}
