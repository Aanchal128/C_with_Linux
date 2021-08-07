/**
 * Program to implement the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings
 * Compilation: gcc -o Ques_14  Ques_14.c
 * Execution:   ./Ques_14
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include <stdio.h>

int strlen(char *st)
{   
    int i = 0;
    while(st[i] != '\0')
        i++;
    return i;
}

char *strncpy(char *s, char *t, int n)
{
    int i;
    // copy first n elements of t in s
	for(i = 0; i < n; i++)
	{
		if(i < strlen(t))
			s[i] = t[i];
		else
		    break;
	}
	s[i] = '\0';
	return s;
}

char *strncat(char *s, char *t, int n)
{
    int i, sl = strlen(s);
    // append first n elements of t to the end of s
	for(i = 0; i < n; i++)
	{
		if(i < strlen(t))
            s[sl + i] = t[i];
		else
			break;
	}
	s[sl + i] = '\0';
	return s;
}

int  strncmp(char *s, char *t, int n)
{
    int i;
	for(i = 0; i < n; i++)
    // [s = AanchalKalra; t = Kalra] ==> 'A' - 'K' = -10 
		if(s[i] != t[i] || s[i] == 0 || t[i] == 0)
			return s[i] - t[i];
	return 0;
}

int main()
{
	char s[10] = "Aanchal", t[10] = "Kalra";

    printf("strncat n = %d -> %s\n", 5, strncat(s, t, 5)); // => Aanchalkalra
    printf("strncmp n = %d -> %d\n", 2, strncmp(s, t, 2)); // => -10
	printf("strncpy n = %d -> %s\n", 4, strncpy(s, t, 4)); // => Kalr

	return 0;
}
