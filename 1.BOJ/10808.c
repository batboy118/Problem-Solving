#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int arr['z' - 'a' + 1];
    char str[105];
    int size;
    int i;

    for (i = 0; i < 'z' - 'a' + 1; i++)
        arr[i] = 0;
    size = read(0, str, 105);
    for (i = 0; i < size; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            arr[str[i] - 'a']++;
    for (i = 0; i < 'z' - 'a' + 1; i++)
        printf("%d ", arr[i]);
    return (0);
}