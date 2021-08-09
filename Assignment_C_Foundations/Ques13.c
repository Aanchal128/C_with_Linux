/**
 * Program to return 1 if the string t occurs at the end of the string s, and zero otherwise
 * Compilation: gcc -o Ques_13  Ques_13.c
 * Execution:   ./Ques_13
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include <stdio.h>

// To find length of the string
int len(char *st)
{
    int i = 0;
    while(st[i] != '\0')
        i++;
    return i;
}

int strend(char s[], char t[])
{
    int i, j, k, l, h;
    i = len(s);
    h = len(t);
    // Checking from (last-size of t)th position of s
    for (l = i - h; l >= 0; l--)
    {
        // Checking for occurence of t in s
        for (j = l, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        // if t occurs at end of string s -> return 1
        if (j == i && t[k] == '\0')
                return 1;
            
    }
    return 0;
}

int main(){
    char t[] = "kd";

    char s[] = "abkdcefkd";
    printf("%d\n",strend(s, t)); // Output: 1

    char z[] = "abkdcefkdg";
    printf("%d",strend(z, t)); // Output: 0

    return 0;
}
