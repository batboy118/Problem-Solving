#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int  R,C,M;
struct info{
	int size;
	int speed;
	int dir;
	int r;
	int c;
};
int map[102][102];
int ans;

vector <info> shark;

void fish(int col){

}

void move(){
	int cnt = 0;
	vector <int> eraseList;
	for(vector<info>::iterator i = shark.begin(); i != shark.end(); i++){
		map[i->r][i->c] = -1;
		int d = 1;
		if(i->dir == 1 || i->dir == 4) d = -1;
		if(i->dir > 2){
			int temp = i->c + (d * i->speed);
			if(temp < 1 || temp > C){
				int gap;
				if(temp < 1) {
					gap = (temp * -1) + 1;
					if(gap + 1 > C) {
						gap = 2 * C - 2 + gap;
						i->c = gap;
					} else{
						i->c = gap;
						i->dir = i->dir == 3 ? 4 : 3;
					}
				}
			}
			else {
				i->c = temp;
			}
			if(i->c == 1) i->dir = 3;
			else if(i->c == C) i->dir = 4;
			if(map[i->r][i->c] == -1)
				map[i->r][i->c] = cnt;
			else{
				if(shark[map[i->r][i->c]].size > i->size)
					eraseList.push_back(cnt);
				else{
					eraseList.push_back(map[i->r][i->c]);
					map[i->r][i->c] = cnt;
				}
			}
		}
		else {
			int temp = i->r + (d * i->speed);
			if(temp < 1 || temp > R){
				int gap;
				if(temp < 1) {
					gap = (temp * -1) + 1;
					if(gap + 1 > R) {
						gap = 2 * R - 2 + gap;
						i->r = gap;
					} else{
						i->r = gap;
						i->dir = i->dir == 1 ? 2 : 1;
					}
				}
			}
			else {
				i->r = temp;
			}
			if(i->r == 1) i->dir = 2;
			else if(i->r == R) i->dir = 1;
			if(map[i->r][i->c] == -1)
				map[i->r][i->c] = cnt;
			else{
				if(shark[map[i->r][i->c]].size > i->size)
					eraseList.push_back(cnt);
				else{
					eraseList.push_back(map[i->r][i->c]);
					map[i->r][i->c] = cnt;
				}
			}
		}
		cnt++;
	}
}

int main(){
	cin >> R >> C >> M;
	memset(map, -1, sizeof(map));
	for(int i = 0; i < M; i++){
		info temp;
		cin >> temp.r >> temp.c >> temp.speed >> temp.dir >> temp.size;
		map[temp.r][temp.c] = i;
		if(temp.dir > 2)
			temp.speed = temp.speed % (2 * C - 2);
		else
			temp.speed = temp.speed % (2 * R - 2);
		shark.push_back(temp);
	}
	for(int col = 1; col <= C; col++){
		fish(col);
		if(col == C) break;

		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; i++){
				printf("%3d ", map[i][j]);
			}
			printf("\n");
		}

		move();
	}
	cout << ans;
	return 0;
}
