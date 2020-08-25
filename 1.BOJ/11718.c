#include <unistd.h>

int main(void)
{
    char str[200];
    int size;

    while ((size = read(0, str, 200)))
        write(1, str, size);
    return (0);
}