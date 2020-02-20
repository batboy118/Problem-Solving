#include <unistd.h>

int ft_strlen(char *str)
{
    int count;

    count = 0;
    while (str[count])
        count++;
    return (count);
}

int main(void)
{
    write(1, "\\    /\\\n )  ( ')\n(  /  )\n \\(__)|", ft_strlen("\\    /\\\n )  ( ')\n(  /  )\n \\(__)|"));
    return (0);
}