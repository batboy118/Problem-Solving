#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int count;
    char str[1000005];
    int i;

    i = 0;
    count = 0;
    scanf("%[^\n]s", str);
    if (str[i] == ' ')
        i++;
    if (str[i])
        count = 1;
    while (str[i])
    {
        if ((str[i] == ' ') && (str[i + 1] != 0))
            count++;
        i++;
    }
    printf("%d", count);
    return (0);
}