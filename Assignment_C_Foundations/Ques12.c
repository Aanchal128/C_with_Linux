/**
 * Program to return the position of the rightmost occurrence of t in s
 * Compilation: gcc -o Ques_12  Ques_12.c
 * Execution:   ./Ques_12
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include <stdio.h>

int strrindex(char s[], char t[])
{
    int i = 0, j, k,l = 0;
    while(s[i]!='\0')
        i++;
    while(t[l]!='\0')
        l++;
    l-=1;

    // Checking from (last-size of t)th position of s
    for ( i -= l; i >= 0; i--)
    {
        // Checking for occurence of t in s
        for ( j = i, k = 0 ; t[k] != '\0' && s[j] == t[k] ; j++, k++ )
            ;
        if ( k > 0 && t[k] == '\0') 
            return i;
    }
    return -1;
}

int main(){
    char t[]="kd";
    char s[]="abkdcdddkdkddf";
  
    printf("%d",strrindex(s, t)); //Output => 10
    return 0;
}
