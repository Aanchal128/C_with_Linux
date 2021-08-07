/**
 * Program to delete each character in s1 that matches any character in the string s2
 * Compilation: gcc -o Ques_10  Ques_10.c
 * Execution:   ./Ques_10
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include <stdio.h>

void squeeze(char *s1, char *s2)
{
    int  i, j, k;
    for (k = 0; s2[k] != '\0'; k++) 
    {   i = 0,j = 0;
        while (s1[i] != '\0')
        { 
            // if a char from s2 matches a char in s1, do not store it in s1
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
            i++;   
        }
        s1[j] = '\0';
    }
}       

int main()
{
    char s1[] = "acbd";
    char s2[] = "bc";
    squeeze(s1, s2);
    printf("%s", s1);
    return 0;
}
