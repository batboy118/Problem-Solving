#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char str[51];
    char temp[51];
    int i;
    int j;

    i = 0;
    while (i < 51)
        temp[i++] = 0;
    scanf("%d", &i);
    while (scanf("%s", str) != -1)
    {
        getchar();
        for (i = 0; str[i] != 0; i++)
        {
            if (temp[i] == 0)
                temp[i] = str[i];
            else if (temp[i] == '?')
                continue;
            else if (temp[i] != str[i])
                temp[i] = '?';
        }
    }
    printf("%s", temp);
    return (0);
}