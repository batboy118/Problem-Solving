#include <stdio.h>

int main()
{
	int a;
	int b;
	int N;

	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		if(a==b)
			printf("0\n");
		else if(a%2 && !(b%2))
		{
			if(a>b)
				printf("2\n");
			else
				printf("1\n");
		}
		else if(!(a%2) && !(b%2))
		{
			if(a>b)
				printf("1\n");
			else
				printf("2\n");
		}
		else if(!(a%2) && b%2)
		{
			if(a>b)
				printf("2\n");
			else
				printf("1\n");
		}
		else
		{
			if(a>b)
				printf("1\n");
			else
				printf("2\n");
		}
	}

	return 0;
}
