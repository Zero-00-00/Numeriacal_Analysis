    #include <stdio.h>

    int main()
    {
        int n;
        printf("Enter the number of data: ");
        scanf("%d", &n);
        double tab[n][2];
        double key, result=0;

        printf("Enter the values of x: \n");
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%lf", &tab[j][i]);
            }
            printf("Enter the Functional values: \n");
        }

        printf("Enter the key value: ");
        scanf("%lf", &key);

        for(int i = 0; i < n; i++)
        {
            double L = 1.0;
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                    L *= (key - tab[j][0]) / (tab[i][0] - tab[j][0]);
            }
            result += tab[i][1] * L;
        }

        printf("The Result is %lf\n", result);
    }