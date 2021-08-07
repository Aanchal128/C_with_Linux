/**
 * Program to convert a string of hexadecimal digit into its equivalent integer value.
 * Compilation: gcc -o Ques_9  Ques_9.c
 * Execution:   ./Ques_9
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

int power(int y)
{
    if (y == 0)
        return 1;
    return 16 * power(y - 1);
}

int htoi(char s[])
{
    int n = 0, i = 0;
    while(s[i] != '\0')
        i++;
    
    int j = 0, k;

    if(s[1] == 'X' || s[1] == 'x')
        k = 1;
    else
        k = -1;
    // if the string contains optional '0x' or '0X' exclude first 2 elements
    for (i -= 1; i > k; i--) 
    {
        int c = upper_to_lower(s[i]);
            if (c >= '0' && c <= '9')
            {
                n += power(j) * (c - '0');
                j += 1;
            }   
            else if (c >= 'a' && c <= 'f')
            {   
                n += power(j) * (c - 'a' + 10);
                j += 1;
            }
    }
    return n;
}

int main(void)
{
    printf("%d\n", htoi("0xffff")); // => 65535
    printf("%d\n", htoi("0x1111")); // => 4369
    printf("%d\n", htoi("E7A9"));   // => 59305
    printf("%d", htoi("FEB6112"));  // => 267084050
    return 0;
}
