#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char str[105];
    int size;
    int i;
    int gap;

    gap = 'a' - 'A';
    size = read(0, str, 105);
    for (i = 0; i < size; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= gap;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += gap;
    }
    write(1, str, size);
    return (0);
}