#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

#define W 0
#define R 1
#define B 2

#define RI 1
#define LE 2
#define UP 3
#define DO 4

struct info{
	int x;
	int y;
	int dir;
};

int N, K;
int map[14][14];
vector<int> lst[14][14];
info mal[10];

int dx[5] = {0, 1, -1, 0, 0 };
int dy[5] = {0, 0, 0, -1, 1};

int move(int m){
	int x = mal[m].x;
	int y = mal[m].y;
	int dir = mal[m].dir;
	int nx = mal[m].x + dx[dir];
	int ny = mal[m].y + dy[dir];

	if(nx < 1 || nx > N || ny < 1 || ny > N || map[ny][nx] == B){
		if(dir == RI) mal[m].dir = LE;
		else if(dir == LE) mal[m].dir = RI;
		else if(dir == UP) mal[m].dir = DO;
		else mal[m].dir = UP;
		dir = mal[m].dir;
		nx = x + dx[dir];
		ny = y + dy[dir];
	}

	if(map[ny][nx] == W){
		int i = 0;
		while(lst[y][x][i] != m){
			i++;
		}
		int lstSize = lst[y][x].size();
		for(int j = i; j < lstSize; j++){
			lst[ny][nx].push_back(lst[y][x][j]);
		}
		for(int j = i; j < lstSize; j++){
			int temp = lst[y][x].back();
			mal[temp].y = ny;
			mal[temp].x = nx;
			lst[y][x].pop_back();
		}
	}
	else if(map[ny][nx] == R){
		int i = 0;
		while(lst[y][x][i] != m){
			i++;
		}
		int lstSize = lst[y][x].size();
		for(int j = lstSize - 1; j >= i; j--){
			lst[ny][nx].push_back(lst[y][x][j]);
		}
		for(int j = lstSize - 1; j >= i; j--){
			int temp = lst[y][x].back();
			mal[temp].y = ny;
			mal[temp].x = nx;
			lst[y][x].pop_back();
		}
	}
	if(lst[ny][nx].size() >= 4) return 1;
	else return 0;
}

int main(){
	cin >> N >> K;
	memset(map, 3, sizeof(map));
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N;j++){
			cin >> map[i][j];
		}
	}
	for(int i = 0; i < K; i++){
		cin >> mal[i].y;
		cin >> mal[i].x;
		cin >> mal[i].dir;
		lst[mal[i].y][mal[i].x].push_back(i);
	}
	int turn = 0;
	while(++turn <= 1000){
		for(int m = 0; m < K; m++){
			if(move(m)){
				cout << turn;
				return 0;
			}
		}
	}
	cout <<  -1;
	return 0;
}
