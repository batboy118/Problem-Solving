#include <unistd.h>
#include <stdio.h>

#define PUSH_F 1
#define PUSH_B 2
#define POP_F 3
#define POP_B 4
#define SIZE 5
#define EMPTY 6
#define FRONT 7
#define BACK 8

int what_is_it(char *str);
void ft_push_front();
void ft_push_back();
void ft_pop_front();
void ft_pop_back();
void ft_size();
void ft_empty();
void ft_front();
void ft_back();

int g_que[100000];
int g_back;

int main()
{
    int N;
    int num;
    int option;
    char str[10];

    scanf("%d", &N);
    while (N--)
    {
        scanf("%s", str);
        option = what_is_it(str);
        if (option == PUSH_F)
            ft_push_front();
        else if (option == PUSH_B)
            ft_push_back();
        else if (option == POP_F)
            ft_pop_front();
        else if (option == POP_B)
            ft_pop_back();
        else if (option == SIZE)
            ft_size();
        else if (option == EMPTY)
            ft_empty();
        else if (option == FRONT)
            ft_front();
        else if (option == BACK)
            ft_back();
    }
    return (0);
}

int what_is_it(char *str)
{
    if (str[0] == 'p' && str[1] == 'u' && str[2] == 's' && str[3] == 'h' && str[4] == '_' && str[5] == 'f')
        return (PUSH_F);
    else if (str[0] == 'p' && str[1] == 'u' && str[2] == 's' && str[3] == 'h' && str[4] == '_' && str[5] == 'b')
        return (PUSH_B);
    else if (str[0] == 'p' && str[1] == 'o' && str[2] == 'p' && str[3] == '_' && str[4] == 'f')
        return (POP_F);
    else if (str[0] == 'p' && str[1] == 'o' && str[2] == 'p' && str[3] == '_' && str[4] == 'b')
        return (POP_B);
    else if (str[0] == 's' && str[1] == 'i' && str[2] == 'z' && str[3] == 'e')
        return (SIZE);
    else if (str[0] == 'e' && str[1] == 'm' && str[2] == 'p' && str[3] == 't' && str[4] == 'y')
        return (EMPTY);
    else if (str[0] == 'f' && str[1] == 'r' && str[2] == 'o' && str[3] == 'n' && str[4] == 't')
        return (FRONT);
    else if (str[0] == 'b' && str[1] == 'a' && str[2] == 'c' && str[3] == 'k')
        return (BACK);
    else
        return (-1);
}

void ft_push_front()
{
    int num;
    int i;

    i = 0;
    scanf("%d", &num);
    while (i <= g_back)
    {
        g_que[g_back - i] = g_que[g_back - i - 1];
        i++;
    }
    g_que[0] = num;
    g_back++;
}

void ft_push_back()
{
    int num;

    scanf("%d", &num);
    g_que[g_back++] = num;
}

void ft_pop_front()
{
    int i;

    i = 0;
    if (g_back == 0)
        printf("-1\n");
    else
    {
        printf("%d\n", g_que[0]);
        g_back--;
        while (i < g_back)
        {
            g_que[i] = g_que[i + 1];
            i++;
        }
    }
}

void ft_pop_back()
{
    if (g_back == 0)
        printf("-1\n");
    else
        printf("%d\n", g_que[--g_back]);
}

void ft_size()
{
    printf("%d\n", g_back);
}

void ft_empty()
{
    if (g_back > 0)
        printf("0\n");
    else
        printf("1\n");
}

void ft_front()
{
    if (g_back == 0)
        printf("-1\n");
    else
        printf("%d\n", g_que[0]);
}

void ft_back()
{
    if (g_back == 0)
        printf("-1\n");
    else
        printf("%d\n", g_que[g_back - 1]);
}