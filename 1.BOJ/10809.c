#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int arr['z' - 'a' + 1];
    char str[105];
    int size;
    int i;

    i = 0;
    while (i < 'z' - 'a' + 1)
        arr[i++] = -1;
    size = read(0, str, 105);
    for (i = 0; i < size; i++)
    {
        if (arr[str[i] - 'a'] == -1)
            arr[str[i] - 'a'] = i;
    }
    for (i = 0; i < 'z' - 'a' + 1; i++)
        printf("%d ", arr[i]);
    return (0);
}