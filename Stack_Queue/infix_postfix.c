/**
 * Program to convert an arithmetic expression from infix notation to postfix notation.
 * Compilation: gcc -o ip infix_postfix.c
 * Execution: ./ip
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
 
// Allocate memory to the stack and initialize it
struct stack* newStack()
{
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
 
    pt->top = -1;
    pt->a = (char*)malloc(sizeof(char) * 10);
 
    return pt;
}

// Add a new element to the top of the stack
void push(struct stack* pt,char value)
{
    if(pt->top < 9)
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

// Checks the precedence of the operator
int priority(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Converts an arithmetic expression from infix notation to postfix notation
void postfix(char* inp)
{
    // stack to store operators and '('
    struct stack *operators = newStack();
    char output[20];

    int i = 0, j = 0;
    // Traverse input string
    while(inp[i] != '\0')
    {
        char el = inp[i];

        // store numbers in the output
        if(el >= '0' && el <= '9')
        {
            output[j] = el;
            j++;
        }
        // push '(' to the stack and pop only when ')' is encountered
        else if (el == '(')
            push(operators, el);
        else if (el == ')')
        {
            // Store operators between '(' and ')' in the output
            while (operators->top > -1 && peek(operators) != '(')
            {
                output[j] = pop(operators);
                j++;
            }  
            
            // pop '('
            pop(operators);
        }
        // Remove operators from the stack which are greater than or equal to in precedence than that of the current operator
         else
        {
            while (operators->top > -1 && priority(el) <= priority(peek(operators)))
            {
                output[j] = pop(operators);
                j++;
            }
            // Store the current operator
            push(operators, el);
        }

        i++;
    }

    // pop all the remaining operators from the stack
    while (operators->top > -1)
    {
        output[j] = pop(operators);
        j++;
    }

    output[j] = '\0';
    printf("%s", output);

    return ;
}

int main()
{
    char input[] = "(1+((3-1)*(4/2)))";

    postfix(input);
    return 0;
}
