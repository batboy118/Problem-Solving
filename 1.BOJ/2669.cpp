// BOJ
// no. 2669
// 직사각형 네개의 합집합의 면적 구하기
// https://www.acmicpc.net/problem/2669
// by JH (batboy118)

#include <iostream>

using namespace std;

int		map[101][101];

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int	i;
	int	edges[4][4];
	int j;
	int count = 0;

	i = -1;
	while(++i < 4)
	{
		j = -1;
		while (++j < 4)
			cin >> edges[i][j];
	}
	i = -1;
	while(++i < 4)
	{
		int	y = edges[i][1];
		while(y < edges[i][3])
		{
			int	x = edges[i][0];
			while(x < edges[i][2])
			{
				if(map[x][y] == 0)
				{
					count++;
					map[x][y]++;
				}
				x++;
			}
			y++;
		}
	}
	cout << count;
	return (0);
}
