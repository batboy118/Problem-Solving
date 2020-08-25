#include <stdio.h>
#include <algorithm>

int main()
{
	int an;
	int pn;
	int a[105];
	int p[105];
	int min;
	int N;
	int i;

	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &an);
		scanf("%d", &pn);
		i = 0;
		while(i < an)
			scanf("%d", &a[i++]);
		i = 0;
		while(i < pn)
			scanf("%d", &p[i++]);
		if(an == 1)
		{
			printf("YES\n");
			continue;
		}
		i = 0;
		int sorted = 1;
		while(i < an - 1)
		{
			if(a[i] > a[i + 1])
			{
				sorted = 0;
				break;
			}
			i++;
		}
		if(sorted == 1)
		{
			printf("YES\n");
			continue;
		}
		int temp = an;
		int j = 0;
		int f;
		while(temp--)
		{
			f = 1;
			i = j + 1;
			min = j;
			while(i < an)
			{
				if(a[min] > a[i])
					min = i;
				i++;
			}
			int ff;
			while(1)
			{
				if(min==j)
					break;
				i = 0;
				ff = 0;
				while(i < pn)
				{
					if(p[i] == min)
					{
						ff = 1;
						break;
					}
					i++;
				}
				if(ff)
				{
					int temp;
					temp = a[min];
					a[min] = a[min -1];
					a[min -1] = temp;
					min--;
				}
				else
				{
					f = 0;
					break;
				}
			}
			if(f == 0)
				break;
			j++;
		}
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
