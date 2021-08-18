/**
 * Program to implement stack using queue
 * Compilation: gcc -o sq stack_queue.c
 * Execution: ./sq
 *
 * LeetCode: "https://leetcode.com/problems/implement-stack-using-queues/" 
 * Assignment 4 - Stacks and Queues
 * @Aanchal, 1910990158, 18/08/2021
 */

typedef struct {
    
    // At most 100 calls will be made to push, pop, top
    // Implementing a stack using 2 QUEUES ----> q1 and q2
    int q1[100];
    int q2[100];   
    int head1;
    int tail1;
    int head2;
    int tail2;
    
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    
    MyStack* my_stack = (MyStack *)malloc(sizeof(MyStack));
    my_stack->head1 = -1;
    my_stack->tail1 = -1;
    my_stack->head2 = -1;
    my_stack->tail2 = -1;
    return my_stack;
    
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    
    if(obj->head1 == -1)
    {
        obj->head1 = 0;
        obj->tail1 += 1;
        obj->q1[(obj->tail1)] = x;
    }
    else if(obj->tail1 < 100 && obj->tail1 > -1)
    {
        obj->tail1 += 1;
        obj->q1[(obj->tail1)] = x;
    }
  
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    
    int el;
    while((obj->head1 < obj->tail1))
    {
        el = obj->q1[(obj->head1)];
        if(obj->head2 == -1)
        {
            obj->head2 = 0;
            obj->tail2 += 1;
            obj->q2[(obj->tail2)] = el;
        }
        else if(obj->tail2 < 100 && obj->tail2 > -1)
        {
            obj->tail2 += 1;
            obj->q2[(obj->tail2)] = el;
        }
        obj->head1 += 1;
    }
    el = obj->q1[(obj->head1)];
    
    obj->head1 = -1;
    obj->tail1 = -1;
    
    while(obj->head2 != -1 && (obj->head2 <= obj->tail2))
    {
        int el2 = obj->q2[(obj->head2)];
        if(obj->head1 == -1)
        {
            obj->head1 = 0;
            obj->tail1 += 1;
            obj->q1[(obj->tail1)] = el2;
        }
        else if(obj->tail1 < 100 && obj->tail1 > -1)
        {
            obj->tail1 += 1;
            obj->q2[(obj->tail1)] = el2;
        }
        obj->head2 += 1;
    }

    return el;

}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    
    return obj->q1[(obj->tail1)];
  
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    
    if(obj->head1 == -1 || obj->head1 > obj->tail1)
        return true;
    return false;
  
}

void myStackFree(MyStack* obj) {
    
    free(obj);
    
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

