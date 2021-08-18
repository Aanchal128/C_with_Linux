/**
 * Program to convert base32 string into base64.
 * Compilation: gcc -o dec_enc base32_base64.c
 * Execution: ./dec_enc
 * 
 * Assignment 3 - Bits and Bytes
 * @Aanchal, 1910990158, 18/08/2021
 * Resources: 
 * "https://www.dcode.fr/base-32-encoding"
 * "https://www.dcode.fr/base-64-encoding"
 */

#include <stdio.h>
#include <string.h>

int toDecimal(char c)
{
    int a = 0;
    if (c >= 'A' && c <= 'Z')
        a = (c - 'A');
    else if (c >= '2' && c <= '7')
        a = (26 + (c - '2'));
    return a;
}

char encode(int value)
{
    if (value <= 25)
        return 'A' + value;
    else if (value <= 51)
        return 'a' + value - 26;
    else if (value <= 61)
        return '0' + value - 52;
    else if (value == 62)
        return '+';
    else if (value == 63)
        return '/';
    else
        return '=';
}

void conversion()
{
    char str[200];
    scanf("%s", str);

    int len = strlen(str);
    while(str[len-1] == '=')
        len -= 1;
    
    int c = 0;
    // To store binary rep of base32 encoded string
    char bin[len*5];
    
    // Decode
    int i = 0;
    while(i < len)
    {   // To convert base32 encoded string to binary string
        int dec = toDecimal(str[i]);
        for (int j = 4; j >= 0; j--) 
        {
            int k = dec >> j;
            if (k & 1)
            {
                bin[c] = '1';
                c++;
            }
            else
            {
                bin[c] = '0';
                c++;
            }
        }
        i++;
    }

    // To fill extra 0's for base64 encoding
    int newlen = c; 
    if(newlen % 6 !=0)
        newlen += (6 - (c % 6));
        
    if(c %6 != 0)
    {
        for(int y = c; y < newlen ; y++)
            bin[y] = '0';
    }

    // Encode
    int l_64 = (newlen/6);
    // Base 64 only works with groups of 4 characters, if needed, fill with = 
    if(l_64 % 4 !=0)
        l_64 += (4-(l_64)%4);

    char b64[l_64];

    int j = 0, k = 5;
    int x = 0;

    // Converting binary string to base64 encoded string
    while(k < newlen)
    {
        int value = 0, base = 1;
        for (int i = k; i >= j; i--) 
        {
            if (bin[i] == '1')
                value += base;
            base = base * 2;
        }
        b64[x] = encode(value);
        x++;
        j = k+1;
        k = j+5;
    }

    printf("%s",b64);

    // fill remaining with "="
    while(x < l_64)
    {
        printf("=");
        x++;
    }
    printf("\n");
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
        conversion();
}
