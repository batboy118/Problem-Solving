#include <stdio.h>

int main(void)
{
    int N;
    char str[55];
    int left;
    int right;
    int i;

    scanf("%d", &N);
    while (N--)
    {
        left = 0;
        right = 0;
        i = 0;
        scanf("%s", str);
        while (str[i])
        {
            if (str[i] == '(')
                left++;
            else if (str[i] == ')')
                right++;
            if (left < right)
                break;
            i++;
        }
        if (left == right)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return (0);
}