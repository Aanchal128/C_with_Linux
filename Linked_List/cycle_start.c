/**
 * "https://leetcode.com/problems/linked-list-cycle-ii/"
 * Compilation: gcc -o cycle cycle_start.c
 * Execution: ./cycle
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
struct ListNode *detectCycle(struct ListNode *head) 
{
    if (head == NULL || head->next == NULL) 
    		return NULL; 
  
    struct ListNode *slow = head, *fast = head; 
  
    slow = slow->next; 
    fast = fast->next->next; 
  
	while (fast && fast->next)
	{ 
		if (slow == fast) 
		    break; 
		slow = slow->next; 
		fast = fast->next->next; 
	}
    
    if (slow != fast) 
        return NULL;

    slow = head; 
    while (slow != fast)
	{ 
        slow = slow->next; 
        fast = fast->next; 
    } 
  
    return slow; 
}
