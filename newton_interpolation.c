#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max 50

int fact(int f) 
{
    if (f == 0) 
        return 1;
    return f * fact(f - 1);
}

void table(double tab[max][max], int n) 
{
    printf("Enter the values of x (in degrees, minutes, seconds): \n");
    for (int j = 0; j < n; j++) 
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        tab[j][0] = x + (y / 60.0) + (z / 3600.0);

        /*if (j > 1 && fabs(tab[1][0] - tab[0][0]) != fabs(tab[j][0] - tab[j - 1][0])) 
        {
            printf("Not Equispace Interval\n");
            exit(0);
        }*/
    }

    printf("Enter the Functional values: \n");
    for (int j = 0; j < n; j++) 
    {
        scanf("%lf", &tab[j][1]);
    }
}

void fwd_diff(double tab[max][max], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        for (int j = 0; j < n - i; j++) 
        {
            tab[j][i + 1] = tab[j + 1][i] - tab[j][i];
        }
    }

    for (int j = 0; j < n; j++) 
    {
        for (int k = 0; k <= n - j; k++) 
        {
            printf("%lf   ", tab[j][k]);
        }
        printf("\n");
    }
}

void bkwd_diff(double tab[max][max], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        for (int j = n - 1; j >= i; j--) 
        {
            tab[j][i + 1] = tab[j][i] - tab[j - 1][i];
        }
    }

    for (int j = 0; j < n; j++) 
    {
        for (int k = 0; k <= j + 1; k++) 
        {
            printf("%lf   ", tab[j][k]);
        }
        printf("\n");
    }
}

double nwtn_fwd_itr(double tab[max][max], int n, double key) 
{
    double h = fabs(tab[1][0] - tab[0][0]);
    double u = (key - tab[0][0]) / h;
    double result = tab[0][1];
    double mul = 1;

    for (int i = 1; i < n; i++) 
    {
        mul *= (u - (i - 1));
        result += (mul / fact(i)) * tab[0][i + 1];
    }

    return result;
}

double nwtn_bkwd_itr(double tab[max][max], int n, double key) 
{
    double h = fabs(tab[1][0] - tab[0][0]);
    double u = (key - tab[n - 1][0]) / h;
    double result = tab[n - 1][1];
    double mul = 1;

    for (int i = 1; i < n; i++) 
    {
        mul *= (u + (i - 1));
        result += (mul / fact(i)) * tab[n - 1][i + 1];
    }

    return result;
}

int main() 
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double tab[max][max];
    double key;
    int check = 0;

    table(tab, n);

    while (check != 1) 
    {
         //degree to decimal convert
        printf("Enter the key value (in degrees, minutes, seconds): ");
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        key = x + (y / 60.0) + (z / 3600.0);

        //normal
        //scanf("%lf", &key);

        if ((key - tab[0][0]) <= (tab[n - 1][0] - key)) 
        {
            fwd_diff(tab, n);
            printf("Using Newton's Forward Interpolation\n");
            printf("%.15lf\n", nwtn_fwd_itr(tab, n, key));
        } 
        else if ((key - tab[0][0]) > (tab[n - 1][0] - key)) 
        {
            bkwd_diff(tab, n);
            printf("Using Newton's Backward Interpolation\n");
            printf("%.15lf\n", nwtn_bkwd_itr(tab, n, key));
        } 
        else 
        {
            printf("Out of Bound\n");
        }

        printf("Enter 1 to Exit or 0 to Continue: ");
        scanf("%d", &check);
    }
}
