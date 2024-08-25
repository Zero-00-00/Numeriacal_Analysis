#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max 50

int arrange(double pre_tab[max][max], double tab[max][max], int n, int check)
{
    for (int i=0; i<n; i++)
    {   
        double sum=0;
        for (int j=0; j<n; j++)
        {
            if (i!=j)
            sum+=fabs(pre_tab[i][j]);
        }

        if (fabs(pre_tab[i][i])==sum)               //check if it can do seidal or not
        check=0;

        if (fabs(pre_tab[i][i])>=sum)
        {
            for (int l=0; l<n+1; l++)
            {
                tab[i][l]=pre_tab[i][l];
            }
        }
    }

    return check;
}

void g_jacobi(double tab[max][max], double x[max], int n)
{
    double p_x[max];
    int error=0;
    //error upto 4 decimal
    while(!error)
    {
        error=1;
        for (int i=0; i<n; i++)                     //gauss jacobi calculate
        {
            double sum=0;
            for (int j=0; j<n; j++)
            {
                if (i!=j)
                {
                    sum+=tab[i][j]*x[j];
                }
            }
            p_x[i]=(tab[i][n]-sum)/tab[i][i];
        }

        for (int k = 0; k < n; k++)
        {
            if (fabs(x[k] - p_x[k]) > 5e-5)
            {
                error = 0;
            }
            x[k] = p_x[k];
        }
    }
}

void g_seidal(double tab[max][max], double x[max], int n)
{
    int error=0;
    //error upto 4 decimal
    while(!error)
    {
        error=1;
        for (int i=0; i<n; i++)                         //gauss seidal calculation
        {
            double sum=0;
            for (int j=0; j<n; j++)
            {
                if (i!=j)
                {
                    sum+=tab[i][j]*x[j];
                }
            }

            double new_x=(tab[i][n]-sum)/tab[i][i];        //new value of x
        
            if (fabs(new_x-x[i])>5e-5)                 //error check
            {
                error=0;
            }

            x[i]=new_x;                                 //update x
        }
    }
}

void print(double x[max], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%lf\n", x[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of variables: ");
    scanf("%d", &n);
    double pre_tab[max][max], tab[max][max], x[max];

    for (int i=0; i<n; i++)                             //initializing x with 0
    {
        x[i]=0;
    }

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            scanf("%lf", &pre_tab[i][j]);
        }
    }

    int check=1;
    check=arrange(pre_tab, tab, n, check);

    int choice;
    while(1)
    {
        printf("1. Gauss Jacobi\n2. Gauss Seidal\n3. Exit\nEnter your Choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Using Gauss Jacobi\n");
                g_jacobi(tab, x, n);
                printf("The Result of  the System of Equation: \n");
                print(x, n);
                break;

            case 2:
                if (check==1)
                {
                    printf("Using Gauss Seidal\n");
                    g_seidal(tab, x, n);
                    printf("The Result of  the System of Equation: \n");
                    print(x, n);
                }
                else
                {
                    printf("For Gauss Seidal the Augmented Matrix must be Strictly Diagonally Dominant");
                    continue;
                }
                break;

            case 3:
                printf("See You Later...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
}