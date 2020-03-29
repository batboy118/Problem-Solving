#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int	N;
int	M;
int	G;
int	R;
int okLand;
int total;
int	map[55][55];
char color[55][55];
int	deep[55][55];
int GA[6];
int RA[6];
int cnt;

struct info
{
	int i;
	int j;
};
info loc[15];


int dx[4] = {0, 1 , 0, -1};
int dy[4] = {1, 0 , -1, 0};

void dfs(int y, int x, char C, int depth)
{
	color[y][x] = C;
	deep[y][x] = depth;
	for(int i =0;  i < 4 ; i++)
	{
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && y + dy[i] < N && x + dx[i] < M && map[y + dy[i]][x + dx[i]] != 0)
		{
			if(deep[y + dy[i]][x + dx[i]] == 0 || deep[y + dy[i]][x + dx[i]] > depth + 1)
				dfs(y+dy[i], x+dx[i], C, depth+1);
			else if(deep[y + dy[i]][x + dx[i]] == depth + 1 && color[y + dy[i]][x + dx[i]] != C)
			{
				color[y + dy[i]][x + dx[i]] = 'F';
				deep[y + dy[i]][x + dx[i]] = -1;
			}

		}

	}
}

int	set()
{
	cnt = 0;
	for(int i = 0; i < R; i++)
	{
		dfs(loc[RA[i]].i, loc[RA[i]].j, 'R', 1);
	}
	for(int i = 0; i < G; i++)
	{
		dfs(loc[GA[i]].i, loc[GA[i]].j, 'G', 1);
	}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
		{
			if(color[i][j] == 'F')
				cnt++;
		}
	if(total < cnt)
		total = cnt;
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	total = 0;
	okLand = 0;

	cin >> N >> M >> G >> R;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 1)
			{
				loc[okLand].i = i;
				loc[okLand].j = j;
				okLand++;
			}
		}
	int GG = 0;
	int RR = 0;

	for (int i = 0; i < (1 << (okLand)); ++i) {
		GG = 0;
		RR = 0;
		for (int j = 0; j<okLand; ++j) {
			if (i & (1 << j))
			{
				GA[GG] = j;
				GG++;
			}
			else
			{
				RA[RR] = j;
				RR++;
			}
			if(GG > G || RR > R)
				break;
		}
		if(GG == G && RR == R)
		{
			memset(color, 0, sizeof(color));
			memset(deep, 0, sizeof(deep));
			set();
		}
	}
	cout << total;
	return 0;
}



//5427 불
//파이썬 itertools
//멱집합 중복되는 문제는..?
