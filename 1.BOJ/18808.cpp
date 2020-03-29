#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int		N;
int		M;
int		C;
int		R;
int		map[45][40];
int		sticker[15][15];
int		K;
int 	cnt;
int 	total;
int		done;

struct info
{
	int i;
	int j;
};

info loc[105];


bool cmp(const info &p1, const info &p2){
    if(p1.i < p2.i){
        return true;
    }
    else if(p1.i == p2.i){
        return p1.j < p2.j;
    }
    else{
        return false;
    }
}


int	set(int x, int y, int depth)
{
	int check = 1;
	for(int a = 0; a < cnt; a++)
	{
		if(map[y + loc[a].i][x + loc[a].j] != 0)
		{
			check = 0;
			break;
		}
		else if(y + loc[a].i >= N || x + loc[a].j >= M)
		{
			check = 0;
			break;
		}
	}
	if(check == 1)
	{
		for(int a = 0; a < cnt; a++)
			map[y + loc[a].i][x + loc[a].j] = 1;
		done = 1;
		return (1);
	}
	if(x < M)
	{
		if(set(x+1, y, depth + 1))
			return (1);
	}
	else if(x >= M && y < N)
	{
		if(set(0, y + 1, depth + 1))
			return (1);
	}
	return (0);
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cin >> N >> M >> K;
	total = 0;

	while(K--)
	{
		done = 0;
		cnt = 0;
		cin >> R >> C;
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
			{
				cin >> sticker[i][j];
				if(sticker[i][j])
				{
					loc[cnt].i=i;
					loc[cnt].j=j;
					cnt++;
				}
			}
		if(set(0, 0, 0))
			total += cnt;
		if(!done)
		{
			int temp;
			for(int z = 0; z < cnt; z++)
			{
				temp = R - loc[z].i - 1;
				loc[z].i = loc[z].j;
				loc[z].j = temp;
			}
			sort(loc, loc+cnt, cmp);
			if(set(0, 0, 0))
				total += cnt;
		}
		if(!done)
		{
			int temp;
			for(int z = 0; z < cnt; z++)
			{
				temp = C - loc[z].i - 1;
				loc[z].i = loc[z].j;
				loc[z].j = temp;
			}
			sort(loc, loc+cnt, cmp);
			if(set(0, 0, 0))
				total += cnt;
		}
		if(!done)
		{
			int temp;
			for(int z = 0; z < cnt; z++)
			{
				temp = R - loc[z].i - 1;
				loc[z].i = loc[z].j;
				loc[z].j = temp;
			}
			sort(loc, loc+cnt, cmp);
			if(set(0, 0, 0))
				total += cnt;
		}
	}
	cout << total;
	return 0;
}


//회전하는 부분
