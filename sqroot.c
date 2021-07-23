/**
 * Program to find square root of a number using binary search.
 * Compilation: gcc sqroot.c -lm
 * Execution: ./a.out
 *
 * @Aanchal,1910990158, 19/07/2021
 * Assignment: Day1_Coding_Assignment
 */

#include <stdio.h>
#include <math.h>

double binsearch(double, double, double, int);
double sqroot(double, int);

void main()
{    // Number and precision
    double number = 0;
    int precision = 0;
    scanf("%lf %d",&number,&precision);

    // Output
    double sq = 0;
    sq = sqroot(number,precision);
    printf("%.*lf",precision,sq);
}

// To find integer part of the square root
double sqroot(double n, int p)
{
    double i = 1;
    double ans;
    while (1)
    {
        if (i*i == n)
            {
                return i;
            }

        else if (i*i > n)
            { // i*i>n, square root lies between i-1 and i
                ans = binsearch(i-1,i,n,p);
                return ans;
            }

        i+=1;
    }
}

// To find square root of a number that lies between i-1 and i
double binsearch(double l, double r, double n, int p)
{
    double mid = (l + r) / 2;

    // Square of mid upto precision
    long int pr = pow(10, p);
    double sq = mid * mid;
    sq = floor(sq * pr) / pr;

    if (sq == n)
        return mid;
    else if (sq > n)
        return binsearch(l,mid,n,p);
    else
        return binsearch(mid,r,n,p);
}
