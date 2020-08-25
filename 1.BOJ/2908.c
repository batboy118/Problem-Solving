#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int input_a;
    int input_b;
    int a;
    int b;

    a = b = 0;
    scanf("%d %d", &input_a, &input_b);
    while (input_a != 0)
    {
        a = input_a % 10 + (a * 10);
        input_a /= 10;
    }
    while (input_b != 0)
    {
        b = input_b % 10 + (b * 10);
        input_b /= 10;
    }
    if (a > b)
        printf("%d", a);
    else
        printf("%d", b);
    return (0);
}