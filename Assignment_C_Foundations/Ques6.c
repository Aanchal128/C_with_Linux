/**
 * Program to check if the given string is palindrome or not.
 * Compilation: gcc -o Ques_6  Ques_6.c
 * Execution:   ./Ques_6
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include <stdio.h>

char upper_to_lower(char s)
{
    if((s >= 'A') && (s <= 'Z'))
        s = 'a' + (s - 'A');
    return s;
}

int palindrome(char str[], int n)
{
    for (int k = 0; k < n; k++)
        str[k] = upper_to_lower(str[k]);

    int i = 0, j = n - 1;
    while(i<j)
    {
        // Ignore spaces
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            i++;
        else if (!(str[j] >= 'a' && str[j] <= 'z'))
            j--;

        // If element is same at front and back then continue
        else if (str[i] == str[j])
            i++, j--;
        // else string is not a palindrome
        else
            return 0;
    }
    return 1;
}

int main()
{
    char str[] = "Never Odd or Even";
    int len = 0;

    while(str[len] != '\0')
        len++;

    if (palindrome(str, len))
        printf("true");
    else
        printf("false");

    return 0;
}
