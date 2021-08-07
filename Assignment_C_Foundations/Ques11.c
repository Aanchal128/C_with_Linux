/**
 * Program to return the first location in the string1 where any character from the string2 occurs, or -1 if s1 contains no characters from s2
 * Compilation: gcc -o Ques_11  Ques_11.c
 * Execution:   ./Ques_11
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include <stdio.h>

int any(char *s1, char *s2)
{
    int j = 0;
    for (int i = 0; s2[i] != '\0'; i++) 
    {  
        while (s1[j] != '\0')
        {
            // if any char from s2 matches a char in s1, return index of the char in s1
            if (s1[j] == s2[i])
                return j;
            j++;   
        }
    }
    return -1;
}       

int main()
{
    char s1[] = "abcdeghdf";

    char s2[] = "df";
    printf("%d", any(s1, s2)); // => Output: 3

    char s3[] = "jh";
    printf("%d\n", any(s1, s3)); // => Output: 6

    char s4[] = "jx";
    printf("%d", any(s1, s4)); // => Output: -1
    
    return 0;
}
