/**
 * Program to return 1 if the string t occurs at the end of the string s, and zero otherwise
 * Compilation: gcc -o Ques_13  Ques_13.c
 * Execution:   ./Ques_13
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include <stdio.h>

int strend(char s[], char t[])
{
    int i = 0, j, k, l;
    while(s[i]!='\0')
        i++;
    // checking from the start of s
    for ( l = 0; l < i; l++)
    {
        // Checking for occurence of t in s
        for ( j = l, k = 0 ; t[k] != '\0' && s[j] == t[k] ; j++, k++ )
            ;
        // if t occurs at end of string s -> return 1
        if ( j == i && t[k] == '\0')
                return 1;
            
    }
    return 0;
}

int main(){
    char t[]="kd";

    char s[]="abkdcefkd";
    printf("%d\n",strend(s, t)); // Output: 1

    char z[] = "abkdcefkdg";
    printf("%d",strend(z, t)); // Output: 0
    return 0;
}
