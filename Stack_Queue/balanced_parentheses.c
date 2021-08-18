/**
 * Program to check whether the sequence of brackets in the given string is balanced or not using 2 stacks.
 * Compilation: gcc -o bp balanced_parentheses.c
 * Execution: ./bp
 * 
 * Assignment 4 - Stacks and Queues
 * @Aanchal, 1910990158, 18/08/2021
 */

#include <stdio.h>

struct stack
{
    int top;
    char *a;
};
 
// To allocate memory to the stack and initialize it
struct stack* newStack()
{
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
 
    pt->top = -1;
    pt->a = (char*)malloc(sizeof(char) * 6);
 
    return pt;
}

// To add a new element to the top of the stack
void push(struct stack* pt,char value)
{
    if(pt->top < 5)
    {
        pt->top += 1;
        pt->a[pt->top] = value;
    }
    else
        printf("Overflow\n");

}

// Removes and returns the element from the top of the stack
char pop(struct stack* pt)
{
    if(pt->top > -1)
    {
        char el = pt->a[pt->top];
        pt->top -= 1;
        return el;
    }
    else
        return -1;
}

// Return but not remove the element at the top of the stack
char peek(struct stack* pt)
{
    if(pt->top > -1)
        return pt->a[pt->top];
    else
        return -1;
}

// To check whether the sequence of brackets is balanced or not
// Returns 1 if balanced else returns 0
int parentheses(struct stack* s)
{
    struct stack *t = newStack();
    while(s->top != -1)
    {
        // Pop closing brackets from stack1 and push in stack2
        char el = pop(s);
        if(el == ')' || el == ']' || el == '}')
            push(t, el);
        // Check for opening brackets in stack1 --> if pair found at top of stack2 pop matching bracket from stack2
        else
        {
            if(el == '{' && peek(t) == '}')
                pop(t);
            else if(el == '[' && peek(t) == ']')
                pop(t);
            else if(el == '(' && peek(t) == ')')
                pop(t);
            else
                return 0;
        }
    }
    return 1;
    
}
int main()
{
    struct stack *s = newStack();
    
    char c;
    for(int i = 0; i < 6; i++)
    {
        scanf("%c",&c);
        push(s,c);
    }

    if(parentheses(s))
        printf("True");
    else
        printf("False");
    
    return 0;
}

