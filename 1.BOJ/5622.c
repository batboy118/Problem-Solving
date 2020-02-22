#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char str[20];
    int size;
    int i;
    int sum;

    sum = 0;
    size = read(0, str, 20);
    for (i = 0; i < size; i++)
    {

        if (str[i] >= 'A' && str[i] <= 'C')
            sum += 3;
        else if (str[i] >= 'D' && str[i] <= 'F')
            sum += 4;
        else if (str[i] >= 'G' && str[i] <= 'I')
            sum += 5;
        else if (str[i] >= 'J' && str[i] <= 'L')
            sum += 6;
        else if (str[i] >= 'M' && str[i] <= 'O')
            sum += 7;
        else if (str[i] >= 'P' && str[i] <= 'S')
            sum += 8;
        else if (str[i] >= 'T' && str[i] <= 'V')
            sum += 9;
        else if (str[i] >= 'W' && str[i] <= 'Z')
            sum += 10;
    }
    printf("%d", sum);
    return (0);
}