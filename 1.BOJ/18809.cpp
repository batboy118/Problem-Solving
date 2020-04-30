#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

#define GREEN 1
#define RED 2
#define COLOR 0
#define TIME 1
#define FLOWER -1

using namespace std;

int map[51][51];
int info[51][51][2];
int N, M, G, R;
int cnt;
int ans;
int temp;
int point[10];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<pair<int,int>> mark;

void bfs()
{
	memset(info, 0, sizeof(info));
	int time = 0;
	queue<pair<int,int>> q;
	for(int i  = 0; i < cnt; i++)
	{
		if(point[i] == GREEN || point[i] == RED)
		{
			info[mark[i].first][mark[i].second][COLOR] = point[i];
			info[mark[i].first][mark[i].second][TIME] = time;
			q.push({mark[i].first, mark[i].second});
		}
	}

	while(!q.empty())
	{
		time++;
		int len = q.size();
		while(len--)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if(info[x][y][COLOR] == FLOWER)
				continue;
			for(int i = 0; i < 4; i++)
			{
				int xx = x + dx[i];
				int yy = y + dy[i];
				if(xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
				if(info[xx][yy][COLOR] == FLOWER || map[xx][yy] == 0) continue;
				if(info[xx][yy][COLOR] == 0)
				{
					info[xx][yy][COLOR] = info[x][y][COLOR];
					info[xx][yy][TIME] = time;
					q.push({xx, yy});
				}
				else if(info[xx][yy][COLOR] != info[x][y][COLOR] && info[xx][yy][TIME] == time)
				{
					info[xx][yy][COLOR] = FLOWER;
					temp++;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M >> G >> R;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0 ; j < M; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 2)
			{
				mark.push_back({i,j});
				cnt++;
			}
		}
	}
	fill(point + cnt - R - G,	point + cnt - R, GREEN);
	fill(point + cnt - R,	point + cnt, RED);
	do{
		temp = 0;
		bfs();
		if(temp > ans)
			ans = temp;
	}while(next_permutation(point, point+cnt));
	cout << ans;
	return 0;
}
