#include <unistd.h>

void put_ascii(char ch)
{
    char tmp;
    if (!ch)
        return;
    put_ascii(ch / 10);
    tmp = ch % 10 + '0';
    write(1, &tmp, 1);
}

int main(void)
{
    char ch;

    read(0, &ch, 1);
    put_ascii(ch);
    return (0);
}