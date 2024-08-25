#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of Variables: ");
    scanf("%d", &n);
    
    // Create the matrix
    double mat[n][n+1];
    
    printf("Enter the augmented matrix (coefficients and constants):\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            scanf("%lf", &mat[i][j]);
        }
    }
    
    // Gauss elimination
    for(int i=0; i<n; i++)
    {
        if (mat[i][i] == 0)
        {
            printf("Mathematical Error: Division by zero\n");
            exit(0);
        }
        for(int j=i+1; j<n; j++)
        {
            double ratio = mat[j][i] / mat[i][i];
            for(int k=0; k<n+1; k++)
            {
                mat[j][k] -= ratio * mat[i][k];
            }
        }
    }

    // Back substitution
    double x[n];
    for(int i=n-1; i>=0; i--)
    {
        x[i] = mat[i][n];
        for(int j=i+1; j<n; j++)
        {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] /= mat[i][i];
    }

    // Print values of the unknown variables
    printf("\nSolution:\n");
    for(int i=0; i<n; i++)
    {
        printf("x%d = %0.3lf\n", i+1, x[i]);
    }

    return 0;
}