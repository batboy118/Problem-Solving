#include <stdio.h>
#include <string.h>

void print_long_num(char *a, char *b, int a_idx, int b_idx, int carry)
{
    int a_tmp;
    int b_tmp;
    int sum_tmp;

    if (a_idx < 0 && !carry && b_idx < 0)
        return;
    if (a_idx >= 0)
        a_tmp = a[a_idx] - '0';
    else
        a_tmp = 0;
    if (b_idx >= 0)
        b_tmp = b[b_idx] - '0';
    else
        b_tmp = 0;
    sum_tmp = a_tmp + b_tmp + carry;
    print_long_num(a, b, a_idx - 1, b_idx - 1, sum_tmp / 10);
    printf("%d", sum_tmp % 10);
}

int main()
{
    char a[10005];
    char b[10005];
    char carry;
    int idx_a;
    int idx_b;

    scanf("%s", a);
    scanf("%s", b);
    idx_a = strlen(a) - 1;
    idx_b = strlen(b) - 1;
    print_long_num(a, b, idx_a, idx_b, 0);
}
