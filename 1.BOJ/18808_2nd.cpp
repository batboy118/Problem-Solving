#include <iostream>

using namespace std;

int N,M,K;
int paper[45][45];
int ans;

struct info
{
	int w;
	int h;
	int shape[13][13];
	int count;
};

info sticker[105];

void fill(info S, int y, int x)
{
	for(int i = 0; i < S.h; i++)
		for(int j = 0; j <  S.w; j++)
			if(S.shape[i][j])
				paper[i+y][j+x] = 1;
}

int paste(info S)
{
	int i;
	int j;
	int y;
	int x;
	for(i = 0; i <= N - S.h; i++)
	{
		for(j = 0; j <= M - S.w; j++)
		{
			for(y = 0; y < S.h; y++)
			{
				for(x = 0; x < S.w; x++)
				{
					if(paper[i+y][j+x] && S.shape[y][x])
						break;
				}
				if(x != S.w && paper[i+y][j+x] && S.shape[y][x])
					break;
			}
			if(x == S.w && y == S.h)
			{
				fill(S, i, j);
				ans += S.count;
				return (1);
			}
		}
	}
	return (0);
}

//90도 우측 회전 : 전치행렬 후 좌우 반전
//90도 좌측 회전 : 전치행렬 후 상하 반전
void rotate(info *S)
{
	int transposed [15][15];
	int tmp;

	for(int i = 0; i < S->h; i++)
		for(int j = 0; j < S->w; j++)
			transposed [j][i] = S->shape[i][j];

	tmp = S->h;
	S->h = S->w;
	S->w = tmp;

	for(int i = 0; i < S->h; i++)
		for(int j = 0; j < S->w; j++)
			S->shape[i][j] = transposed[i][S->w - 1 - j];
}

int main()
{
	cin >> N >> M >> K;
	for(int i = 0; i < K; i++)
	{
		cin >> sticker[i].h >> sticker[i].w;
		for(int j = 0; j < sticker[i].h; j++)
			for(int k = 0; k < sticker[i].w; k++)
			{
				cin >> sticker[i].shape[j][k];
				if(sticker[i].shape[j][k])
					sticker[i].count++;
			}
	}
	for(int i = 0; i < K; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(paste(sticker[i]))
				break;
			if(j == 3)
				break;
			rotate(&sticker[i]);
		}
	}
	cout << ans;
	return 0;
}
