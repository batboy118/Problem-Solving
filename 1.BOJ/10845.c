#include <unistd.h>
#include <stdio.h>

#define PUSH 1
#define POP 2
#define SIZE 3
#define EMPTY 4
#define FRONT 5
#define BACK 6

int what_is_it(char *str);
void ft_push();
void ft_pop();
void ft_size();
void ft_empty();
void ft_front();
void ft_back();

int g_que[100000];
int g_back;
int g_front;

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
        if (option == PUSH)
            ft_push();
        else if (option == POP)
            ft_pop();
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
    if (str[0] == 'p' && str[1] == 'u' && str[2] == 's' && str[3] == 'h')
        return (PUSH);
    else if (str[0] == 'p' && str[1] == 'o' && str[2] == 'p')
        return (POP);
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

void ft_push()
{
    int num;

    scanf("%d", &num);
    g_que[g_back++] = num;
}

void ft_pop()
{
    if (g_back == g_front)
        printf("-1\n");
    else
        printf("%d\n", g_que[g_front++]);
}

void ft_size()
{
    printf("%d\n", g_back - g_front);
}

void ft_empty()
{
    if (g_back - g_front > 0)
        printf("0\n");
    else
        printf("1\n");
}

void ft_front()
{
    if (g_back == g_front)
        printf("-1\n");
    else
        printf("%d\n", g_que[g_front]);
}

void ft_back()
{
    if (g_back == g_front)
        printf("-1\n");
    else
        printf("%d\n", g_que[g_back - 1]);
=======
#include <unistd.h>
#include <stdio.h>

#define PUSH 1
#define POP 2
#define SIZE 3
#define EMPTY 4
#define FRONT 5
#define BACK 6

int what_is_it(char *str);
void ft_push();
void ft_pop();
void ft_size();
void ft_empty();
void ft_front();
void ft_back();

int g_que[100000];
int g_back;
int g_front;

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
        if (option == PUSH)
            ft_push();
        else if (option == POP)
            ft_pop();
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
    if (str[0] == 'p' && str[1] == 'u' && str[2] == 's' && str[3] == 'h')
        return (PUSH);
    else if (str[0] == 'p' && str[1] == 'o' && str[2] == 'p')
        return (POP);
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

void ft_push()
{
    int num;

    scanf("%d", &num);
    g_que[g_back++] = num;
}

void ft_pop()
{
    if (g_back == g_front)
        printf("-1\n");
    else
        printf("%d\n", g_que[g_front++]);
}

void ft_size()
{
    printf("%d\n", g_back - g_front);
}

void ft_empty()
{
    if (g_back - g_front > 0)
        printf("0\n");
    else
        printf("1\n");
}

void ft_front()
{
    if (g_back == g_front)
        printf("-1\n");
    else
        printf("%d\n", g_que[g_front]);
}

void ft_back()
{
    if (g_back == g_front)
        printf("-1\n");
    else
        printf("%d\n", g_que[g_back - 1]);
}