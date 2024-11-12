#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x)
{
    return pow(x, 2) + 2 * x - 0.9975;
}

double deri(double x)
{
    return 2 * x + 2;
}

int main()
{
    double x, x1, error = 1;

    printf("The initial guess: ");
    scanf("%lf", &x);

    while(fabs(error) > 5e-5)
    {
        x1 = x - (func(x) / deri(x));
        error = fabs(x1 - x);
        x = x1;
    }
    printf("The Result: %lf", x);
}