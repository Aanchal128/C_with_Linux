/**
 * Program to implement min stack
 * Compilation: gcc -o ms min_stack.c
 * Execution: ./ms
 *
 * LeetCode: "https://leetcode.com/problems/min-stack/" 
 * Assignment 4 - Stacks and Queues
 * @Aanchal, 1910990158, 18/08/2021
 */

typedef struct {
    
    // At most 30000 calls will be made to push, pop, top, and getMin
    int a[30000];   
    int top;
    
    // To store minimum values
    int min[25];
    // To keep count of minimum values pushed till now
    int count;
    
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    
    MinStack * min_stack = (MinStack *)malloc(sizeof(MinStack));
    min_stack->top = -1;
    min_stack->count = 0;
    return min_stack;
    
}

void minStackPush(MinStack* obj, int val) {

    // Adding elements to the top of the stack
    if(obj->top >= -1)
    {
        obj->top += 1;
        obj->a[(obj->top)] = val;
        
    }
    
    // Storing minimum value
    if(obj->count == 0 || val <= obj->min[(obj->count)] )
    {
        obj->count += 1;
        obj->min[obj->count] = val;
        
    }
  
}

void minStackPop(MinStack* obj) {
    
    int el = obj->a[(obj->top)];
    
    // Removing element from the top of the stack
    if(obj->top > -1)
        obj->top -= 1;
    
    // if minimum element is removed from the stack-> point to next minimum value 
    if(el == obj->min[(obj->count)])
        obj->count -= 1;
  
}

//  To get the top element of the stack
int minStackTop(MinStack* obj) {
    
    if(obj->top > -1)
        return obj->a[(obj->top)];
    return 0;
}

// To get the minimum element in the stack
int minStackGetMin(MinStack* obj) {
  
    if(obj->top > -1 && obj->count >= 0)
        return obj->min[(obj->count)];
    return 0;
}

void minStackFree(MinStack* obj) {
    free(obj); 
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
