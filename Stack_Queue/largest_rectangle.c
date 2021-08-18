/**
 * Program to find the largest rectangle in the histogram.
 * Compilation: gcc -o lr largest_rectangle.c
 * Execution: ./lr
 *
 * LeetCode: "https://leetcode.com/problems/largest-rectangle-in-histogram/" 
 * Assignment 4 - Stacks and Queues
 * @Aanchal, 1910990158, 18/08/2021
 */

int pop(int *s, int top)
{
    return s[top];
}

void push(int *s,int top, int n)
{
    top += 1;
    s[top] = n; 
}

// To calculate area of the bar
int Area(int* heights, int* stack, int t, int i)
{
    int area = -1;
    
    int h = heights[pop(stack, t)];
    t--;
                
    // If only 1 element was there in the stack
    if(t == -1)
    {
        area = h * i;
    }    
                    
    else
    {
        area = h * (i-stack[t]-1);
    } 
        
    return area;
}

int largestRectangleArea(int* heights, int heightsSize)
{
    
    int stack[heightsSize];
    int top = -1, area = -1, i = 0, marea = -1;
    
    for( i = 0; i < heightsSize; i++)
    {
        // Push first index to the stack
        if(top == -1) 
        {
            push(stack, top, i);
            top++;
        }
        // Push if height of current bar is greater than height of rectangle at top of the stack
        else if(heights[i] >= heights[stack[top]])
        {
            push(stack, top, i);
            top++;
        }
        // Pop until a bar smaller height  is found
        // Caculate area of popped bar
        else
        {   
            while(heights[i] < heights[stack[top]])
            {
                area = Area(heights, stack, top, i);
                top--;
                if(area > marea)
                    marea = area;
                if(top == -1)
                    break;
            }
            push(stack, top, i);
            top++;
        }
        
    
    }
    // calculate area of remaining bars in the stack
    if(stack[top]+1 == heightsSize)
    {
        while(top > -1)
        {
            area = Area(heights, stack, top, i);
            top--;
            if(area > marea)
                marea = area;
        }
    }
    
    return marea;
}
