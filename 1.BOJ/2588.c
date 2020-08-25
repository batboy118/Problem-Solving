#include <stdio.h>

int main()
{
    int a;
    int b;
    int c;

    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d\n", a * (b % 10));
    printf("%d\n", a * ((b / 10) % 10));
    printf("%d\n", a * ((b / 100) % 10));
    printf("%d\n", (a * b));
}