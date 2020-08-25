#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

int  R,C;
int T;
int map[55][55];
int add[55][55];
struct info
{
	int x;
	int y;
};
info aircon[2];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void spread(){
	for(int y = 1; y <= R; y++){
		for(int x = 1; x <= C; x++){
			if(map[y][x] >1){
				int cnt = 0;
				int val = map[y][x] / 5;
				for(int i = 0; i < 4; i++){
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(nx < 1 || nx > C || ny < 1 || ny > R || map[ny][nx] == -1) continue;
					cnt++;
					add[ny][nx] += val;
				}
				add[y][x] -= (val * cnt);
			}
		}
	}
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			map[i][j] += add[i][j];
			if(map[i][j] < 0) map[i][j] = 0;
		}
	}
}

void clean(){
	int x0 = aircon[0].x;
	int y0 = aircon[0].y;
	int x1 = aircon[1].x;
	int y1 = aircon[1].y;
	for(int i = y0 - 1; i > 1; i--){
		map[i][1] = map[i - 1][1];
	}
	for(int i = y1 + 1; i < R; i++){
		map[i][1] = map[i + 1][1];
	}
	for(int i = 1; i < C; i++){
		map[1][i] = map[1][i + 1];
		map[R][i] = map[R][i + 1];
	}
	for(int i = 1; i < y0; i++){
		map[i][C] = map[i + 1][C];
	}
	for(int i = R; i > y1; i--){
		map[i][C] = map[i - 1][C];
	}
	for(int i = C; i > 1; i--){
		map[y0][i] = map[y0][i - 1];
		map[y1][i] = map[y1][i - 1];
	}
}

int main(){
	cin >> R >> C >> T;
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			cin >> map[i][j];
			if(map[i][j] == -1){
				if(aircon[0].x){
					aircon[1].x = j;
					aircon[1].y = i;
				}
				else{
					aircon[0].x = j;
					aircon[0].y = i;
				}
			}
		}
	}
	while(T--){
		memset(add, 0, sizeof(add));
		map[aircon[0].y][aircon[0].x] = -1;
		map[aircon[1].y][aircon[1].x] = -1;
		spread();
		clean();
	}
	int ans = 0;
	map[aircon[0].y][aircon[0].x] = 0;
	map[aircon[1].y][aircon[1].x] = 0;
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			ans += map[i][j];
		}
	}
	cout << ans;
	return 0;
}
