#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char str[101];
    int count_num;
    int count_lowercase;
    int count_uppercase;
    int count_space;
    int size;
    int i;

    while (scanf("%[^\n]s", str) != -1)
    {
        getchar();
        count_num = count_space = count_lowercase = count_uppercase = 0;
        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
                ++count_num;
            else if (str[i] == ' ')
                ++count_space;
            else if (str[i] >= 'a' && str[i] <= 'z')
                ++count_lowercase;
            else if (str[i] >= 'A' && str[i] <= 'Z')
                ++count_uppercase;
        }
        printf("%d %d %d %d\n", count_lowercase, count_uppercase, count_num, count_space);
    }
    return (0);
}