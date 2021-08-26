/**
 * Program to convert base32 string into base64.
 * Compilation: gcc -o dec_enc base32_base64.c
 * Execution: ./dec_enc
 * 
 * Assignment 3 - Bits and Bytes
 * @Aanchal, 1910990158, 18/08/2021
 *
 * Resources: 
 * "https://www.dcode.fr/base-32-encoding"
 * "https://www.dcode.fr/base-64-encoding"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toDecimal(char c)
{
    int a = 0;

    if(c >= 'A' && c <= 'Z')
        a = (c - 'A');
    else if(c >= '2' && c <= '7')
        a = (26 + (c - '2'));

    return a;
}

int* b32_to_binary(char input[], int len, int* binlen)
{
    int *bin = (int*)malloc(sizeof(int) * 40000);

    int i = 0, bl = 0;
    while(i < len)
    {
        char c = input[i];
        if(c != '=')
        {
            int dec = toDecimal(c);
            // 5 bit binary
            for(int j = 4; j >= 0; j--)
            {
                int k = ((dec >> j) & 1) ? 1 : 0;
                bin[bl] = k;
                bl++;
            }
        }
        else
            break;
        i++;
    }

    // while decoding Base32 message is divided into bytes (8-bits) and remaining bits are discarded
    // removing remaining bits
    bl = 8*(bl/8);
    // while encoding message into Base64-->message is split into 6 bits
    if(bl%6 != 0)
    {
        int new_bl = 6*((bl/6) + 1);
        // adding 0's
        while(bl < new_bl)
        {
            bin[bl] = 0;
            bl++;
        }
        bl = new_bl;
    }
    *binlen = bl;

    return bin;
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

char* binary_to_b64(int bin[], int bin_len)
{
    // Base 64 only works with groups of 4 characters, if needed, fill with =
    int final_len = (bin_len/6);
    if(final_len % 4 != 0)
        final_len = 4*( ((bin_len/6) / 4) + 1);

    char *b64 = (char*)malloc(sizeof(char) * final_len);

    int j = 5, k = 0, i = 0;
    while(j < bin_len)
    {
        int value = 0, base = 1;
        // taking 6 bits at a time --> ascii
        while(j >= i)
        {
            if (bin[j])
                value += base;
            base = base * 2;
            j--;
        }
        b64[k] = encode(value);
        k++;
        i += 6;
        j = i+5;
    }

    // padding
    while(k < final_len)
    {
        b64[k] = '=';
        k++;
    }
    b64[k] = '\0';

    return b64;
}

void conversion()
{
    char input[200];
    scanf("%s", input);
    int len = strlen(input);

    // Base32 -> binary
    int bin_len = 0;
    int *bin = b32_to_binary(input, len, &bin_len);
    
    // binary -> Base64
    char *b_64 = binary_to_b64(bin, bin_len);

    printf("%s\n",b_64);
}

int main()
{
    int tc;
    scanf("%d",&tc);

    while(tc--)
        conversion();

    return 0;
}
