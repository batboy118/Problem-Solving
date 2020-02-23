#include <stdio.h>

int main()
{
    double res;
    double a;
    double b;

    scanf("%lf", &a);
    scanf("%lf", &b);
    res = a / b;
    printf("%.10f", res);
}