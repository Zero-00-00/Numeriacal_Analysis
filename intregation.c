#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double trapizoidal(double tab[][2], int n, double h)
{
    double sum=0;
    for(int i=1; i<n-1; i++)
    sum+=tab[i][1];

    return ((h/2)*((tab[0][1]+tab[n-1][1])+2*sum));
}

double simpsons(double tab[][2], int n, double h)
{
    double odd=0, even=0;
    for(int i=1; i<n-1; i++)
    {
        if(i%2==0)
        even+=tab[i][1];
        else
        odd+=tab[i][1];
    }
    return ((h/3)*((tab[0][1]+tab[n-1][1])+2*even+4*odd));
}

void table(double tab[][2], int n)
{
    printf("Enter the Values of Data Points\n");
    for(int i=0; i<n; i++)
    {
        scanf("%lf", &tab[i][0]);
    }
    printf("Enter the Functional Values\n");
    for(int i=0; i<n; i++)
    {
        scanf("%lf", &tab[i][1]);
    }
}

int main()
{
    int n;
    printf("Enter the Number of data points: ");
    scanf("%d", &n);

    double tab[n][2];
    printf("Creating Table\n");
    table(tab, n);
    double h=fabs(tab[1][0] - tab[0][0]);

    int choice;
    while(1)
    {
        printf("1. Trapizoidal\n2. Simpson's 1/3 Rule\n3. Exit\nEnter your Choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
            printf("Using Trapizoidal\n");
            printf("The Result of Intregation: %lf\n\n", trapizoidal(tab, n, h));
            break;

            case 2:
            if(n%2!=0)
            {
                printf("Using Simpson's 1/3 Rule\n");
                printf("The Result of Intregation: %lf\n\n", simpsons(tab, n, h));
            }
            else
            printf("The number of data points must be odd\n\n");
            break;

            case 3:
                printf("See You Later...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
}