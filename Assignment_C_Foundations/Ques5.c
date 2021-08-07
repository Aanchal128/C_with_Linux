/**
 * Program to multiply the given 2 matrices.
 * Compilation: gcc -o Ques_5  Ques_5.c
 * Execution:   ./Ques_5
 *
 * Assignment_1 - C Foundations
 * @Aanchal, 1910990158, 7/8/2021
 */

#include <stdio.h>

// Function to multiply 2 matrices
// Parameters: m1,m2 Input matrices
// ans[][]: Matrix to store the result
void multiply(int m1[2][2], int m2[2][2], int ans[2][2])
{
    int i, j, k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            ans[i][j] = 0;
            for (k = 0; k < 2; k++)
                ans[i][j] += m1[i][k] * m2[k][j];
        }
    }
}
 
int main()
{
    int Matrix1[2][2] = { {1, 2}, {3, 4} };
    int Matrix2[2][2] = { {1, 1}, {1, 1} };
 
    int ans[2][2];
    int i, j;

    multiply(Matrix1, Matrix2, ans);
    
    for (i = 0; i < 2; i++) 
    {
        for (j = 0; j < 2; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
 
    return 0;
}
