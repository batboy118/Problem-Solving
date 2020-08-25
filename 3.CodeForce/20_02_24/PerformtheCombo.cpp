#include <stdio.h>
#include <algorithm>

int alpha[10005][26];

int main()
{
	int N;
	int i;
	int cn;
	int m;
	char combo[200010];
	int mistake[200010];

	scanf("%d", &N);
	while(N)
	{
		scanf("%d", &cn);
		scanf("%d", &m);
		scanf("%s", combo);
		i = 0;
		while(i < m)
			scanf("%d",&mistake[i++]);
		int j;
		j= 0;
		i= 0;
		while(i < cn)
		{
				combo[i] -= 'a';
				i++;
		}
		while(j<m)
		{
			i = 0;
			while(i < mistake[j])
			{
				alpha[N][combo[i]]++;
				i++;
			}
			j++;
		}
		i = 0;
		while(i < cn)
			alpha[N][combo[i++]]++;
		i = 0;
		while(i < 26)
			printf("%d ", alpha[N][i++]);
		printf("\n");
		N--;
	}
	return 0;
}
