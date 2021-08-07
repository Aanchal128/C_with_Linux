/**
 * Program to find the count of the number of vowels and consonants in the given string.
 * Compilation: gcc -o Ques_3  Ques_3.c
 * Execution:   ./Ques_3
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include <stdio.h>

// Function to covert a lowercase character into uppercase
char lower_to_upper(char s)
{
    if((s >= 'a') && (s <= 'z'))
        s = 'A' + (s - 'a');
    return s; 
}

int main()
{   char str[50];
    scanf("%[^\n]s",str);

    int i = 0, vowel = 0, cons = 0;
    while(str[i] != '\0')
    {   
        char ch = lower_to_upper(str[i]);
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' )
            vowel++;
        else
            cons++;
        i++;
    }

    printf("Vowels = %d Consonants = %d", vowel, cons);

    return 0;
}
