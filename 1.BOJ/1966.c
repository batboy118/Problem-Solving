#include <stdio.h>

int main(void)
{
    int tc;
    int N;
    int M;
    int count;
    int flag;
    int temp;
    int arr[200];

    scanf("%d", &tc);
    while(tc--)
    {
        count = 0;
        scanf("%d", &N);
        scanf("%d", &M);
        for(int i =0; i<N; i++)
            scanf("%d", &arr[i]);
        while(1)
        {
            flag = 0;
            for(int i = 1; i < N; i++)
            {
                if(arr[0] < arr[i])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
            {
                if(M==0)
                    M = N-1;
                else
                    M--;                
                temp = arr[0];
                for(int i = 1; i < N; i++)
                    arr[i - 1] = arr[i];
                arr[N-1] = temp;
            }
            else
            {
                count++;   
                if(M==0)
                    break;
                else
                    M--;                
                for(int i = 1; i < N; i++)
                    arr[i - 1] = arr[i];
                N--;
            }
        }
        printf("%d\n", count);
    }
    return (0);
}