/**
 * Program to reverse the character string
 * Compilation: gcc -o Ques_8  Ques_8.c
 * Execution:   ./Ques_8
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include <stdio.h>

void reverse(char *s, int n)
{   
    int i = 0, j = n - 1;
    while(i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main()
{   
    char str[] = "hello world";
    int len = 0;
    while(str[len]!='\0')
        len++;
    
    reverse(str,len);
    printf("%s",str);
    return 0;
}
