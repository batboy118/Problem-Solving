#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char str[1001];
    char temp[1001];
    int i;
    int j;
    char ch;

    scanf("%d", &i);
    while (scanf("%s", str) != -1)
    {
        ch = getchar();
        for (i = 0; str[i] != 0; i++)
            ;
        for (j = 0; j < i; j++)
            temp[j] = str[i - j - 1];
        temp[i] = 0;
        printf("%s", temp);
        if (ch == ' ')
            printf(" ");
        else if (ch == '\n')
            printf("\n");
    }
    return (0);
}