/**
 * Program to implement bitwise operators.
 * Compilation: gcc -o bo bitwise_operators.c
 * Execution: ./bo
 * 
 * Assignment 3 - Bits and Bytes
 * @Aanchal, 1910990158, 18/08/2021
 * Resource: "https://www.learncpp.com/cpp-tutorial/signed-integers/"
 */

 #include <stdio.h>

// bitAnd - x & y using only ~ and |
int bitAnd (int x, int y) 
{
    return ~(~x | ~y);   // bitAnd(6, 5) = 4
}

// bitXor - x ^ y using only ~ and &
int bitXor (int x, int y)
{
    return ~(~(~x & y) & ~(x & ~y)); // bitXor(4, 5) = 1
}


// sign - return 1 if positive, 0 if zero, and -1 if negative
int sign(int x) 
{
    x = (x>>31) | !(!x);  // (-23)>>31 = 0xffffffff = [-2^31 + (2^31-1)] = -1
                          // (130)>>31 = 0 --> !!(130) = 1 --> 0 | 1 = 1
                          // (0>>31) = 0 --> !!(0) --> 0 | 0 = 0
    return x;
}

// getByte - extract byte n from word x
int getByte(int x, int n) 
{
    n = n << 3;             // n<<3 = number of bits , [0xff = 255] i.e, & with 8 1's to extract LS byte     
    return ((x >> n) & 0xFF);  // getByte(0x12345678, 1) = 0x56
}

// logicalShift - shift x to the right by n, using a logical shift
int logicalShift(int x, int n) 
{    // logicalShift(0x87654321, 4) = 0x8765432
    // 0x87654321 >> 4 = 0xf8765432;
    // to extract 8765432 ->  0xf8765432 & 0x0fffffff
    // to get 0x0fffffff

    int y = 1 << 31; // 0x80000000
    y = y >> n;      // n = 4 -> 0xf8000000
    y = y << 1;      // 0xf0000000
    y = ~y;          // 0x0fffffff
    return (x >> n) & y;
}

// Return x with the n bits that begin at position p inverted.
int invert (int x, int p, int n) 
{
    // ex: 26 --> 011010, p = 2, n = 2
    // i.e, invert from 2nd position to 1st position--> 011 01 0 --> 011 10 0
    // 011010 --> 011100----> to invert 011010 ^ 000110 = 011100
    
    int x1 = 0xffffffff; // all 1's [ex: 111111]
    x1 = x1 << n;        // 111111 << 2 --> 111100
    x1 = ~x1 << p;       // 000011 << 2   --> 001100
    x1 = x1 >> n;        // 001100 >> 2 --> 000011  
    x1 = x1 << 1;        // 000110
    return x^x1;


}

int main()
{
    printf("%d\n",bitAnd(6,5));
    printf("%d\n",bitXor(4,5));
    printf("%d\n",sign(0));
    printf("%x\n",getByte(0x12345678, 2));
    printf("%x\n",logicalShift(0x87654321, 8));
    printf("%d\n",invert(26,2,2));
    
    
    return 0;
}

