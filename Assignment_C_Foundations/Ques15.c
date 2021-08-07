/**
 * Program to evaluate a reverse Polish expression from the command line
 * Compilation: gcc -o Ques_15  Ques_15.c
 * Execution:   ./Ques_15
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include <stdio.h>

int a[10];
int top = -1;

int is_empty()
{
    if(top == -1)
        return 1;
    return 0;
}

// to add an element to the top of stack
void push(int value)
{
    if(top < 9)
    {
        top += 1;
        a[top] = value;
    }
    else
        printf("Overflow\n");

}

// to remove an element from the top of stack
int pop()
{
    if(!is_empty())
    {
        int el = a[top];
        top -= 1;
        return el;
    }
    else
    {
        printf("Empty Stack\n");
        return -1;
    }
}

// To convert string of digits into its numeric equivalent
int atoi(char* s)
{
    int i, n;
    n = 0;
 
    for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
 
    return n;
}

int main(int argc, char *argv[])
{
    int i = 1, j, k;
    printf("Evaluates to:");
	while (i < argc) 
    {   
		if (*argv[i] == '+') 
        {   j = pop();
            k = pop();
            printf("\n%d + %d",j,k);
			push(j+k);
		}

		else if (*argv[i] == '-') 
        {
			j = pop();
            k = pop();
            printf("\n%d - %d",k,j);
			push(k - j);
		}

		else if (*argv[i] == '*') 
        {
		    j = pop();
            k = pop();
            printf("\n%d * %d",j,k);
			push(j*k);
		}

		else if (*argv[i] == '/') 
        {
            j = pop();
            k = pop();
			if(j != 0)
			{
			    printf("\n%d / %d",k,j);
				push( k / j);
			}
			else
				printf("Invalid\n");
		}

        // push the operands to the stack
		else
			push(atoi(argv[i]));
		i++;
	}
    // Input: 2 3 4 + "*" 
    // Output: (4+3)*2 = 14
	printf("\nResult = %d", pop());
	return 0;
}
