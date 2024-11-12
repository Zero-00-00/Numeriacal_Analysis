
// function is (x^3 + y)

#include <stdio.h>
#include <math.h>

double func(double x, double y)
{
    return pow(x, 3) + y;
}

int main()
{
    double x = 0, y_prv = 1, y_now = 0, h = 0.01, error = 0, target = 0.02;
    int count = 0;

    printf("x y\n");
    printf("%lf, %lf\n", x, y_prv);

    while(x != target)
    {
        y_now = y_prv + (h * func(x, y_prv));
        y_prv = y_now;
        x = x + h;
        printf("%lf, %lf\n", x, y_prv);
    }

    printf("%.9lf\n", y_now);
}


/*
// function is (y - x / y + x)

#include <stdio.h>
#include <math.h>

double func(double x, double y)
{
    return (y - x)/(y + x);
}

int main()
{
    double x = 0, y_prv = 1, y_now = 0, h = 0.02, error = 0, target = 0.04;
    int count = 0;

    printf("x y\n");
    printf("%lf, %lf\n", x, y_prv);

    while(x != target)
    {
        y_now = y_prv + (h * func(x, y_prv));
        y_prv = y_now;
        x = x + h;
        printf("%lf, %lf\n", x, y_prv);
    }

    printf("%.9lf\n", y_now);
}
*/