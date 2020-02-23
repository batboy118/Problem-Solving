#include <unistd.h>
#include <stdio.h>

#define PUSH 1
#define POP 2
#define SIZE 3
#define EMPTY 4
#define TOP 5

int what_is_it(char *str);
void ft_push();
void ft_pop();
void ft_size();
void ft_empty();
void ft_front();
void ft_top();

int g_stack[100000];
int g_top;

int main()
{
    int N;
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
        else if (option == TOP)
            ft_top();
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
    else if (str[0] == 't' && str[1] == 'o' && str[2] == 'p') 
        return (TOP);
    else
        return (-1);
}

void ft_push()
{
    int num;

    scanf("%d", &num);
    g_stack[g_top++] = num;
}

void ft_pop()
{
    if (g_top < 1)
        printf("-1\n");
    else
        printf("%d\n", g_stack[--g_top]);
}

void ft_size()
{
    printf("%d\n", g_top);
}

void ft_empty()
{
    if (g_top < 1)
        printf("1\n");
    else
        printf("0\n");
}

void ft_top()
{
    if (g_top < 1)
        printf("-1\n");
    else
        printf("%d\n", g_stack[g_top - 1]);
}