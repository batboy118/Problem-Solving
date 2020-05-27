#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>

using namespace std;

int  R, C, M;
struct info {
	int size;
	int speed;
	int dir;
	int r;
	int c;
};
int map[103][103];
int ans;

vector <info> shark;

int nd[5] = { 0, 2, 1, 4, 3 };
int nc[5] = { 0, 0, 0, 1, -1 };
int nr[5] = { 0, -1, 1, 0, 0 };

void fish(int col) {
	for (int i = 1; i <= R; i++) {
		if (map[i][col] != -1) {
			ans += shark[map[i][col]].size;
			shark.erase(shark.begin() + map[i][col]);
			break;
		}
	}
}

void move() {
	for (unsigned int i = 0; i < shark.size(); i++) {
		int cc = shark[i].c;
		int cr = shark[i].r;
		int cnt = shark[i].speed;
		int dir = shark[i].dir;
		int sz = shark[i].size;
		while (cnt--) {
			cc += nc[dir];
			cr += nr[dir];
			if (cc == 1 && nc[dir]) dir = 3;
			else if(cc == C && nc[dir]) dir = 4;
			else if(cr == 1 && nr[dir]) dir = 2;
			else if(cr == R && nr[dir]) dir = 1;
		}
		shark[i].dir = dir;
		shark[i].c = cc;
		shark[i].r = cr;
		if (map[cr][cc] == -1) {
			map[cr][cc] = i;
		}
		else {
			if (shark[map[cr][cc]].size > sz) {
				shark.erase(shark.begin() + i--);
			}
			else {
				for(int j = map[cr][cc] + 1; j < i; j++){
					map[shark[j].r][shark[j].c]--;
				}
				shark.erase(shark.begin() + map[cr][cc]);
				map[cr][cc] = --i;
			}
		}
	}
}

int main() {
	cin >> R >> C >> M;
	memset(map, -1, sizeof(map));
	shark.reserve(10005);
	for (int i = 0; i < M; i++) {
		info temp;
		cin >> temp.r >> temp.c >> temp.speed >> temp.dir >> temp.size;
		map[temp.r][temp.c] = i;
		if (temp.dir > 2)
			temp.speed = temp.speed % (2 * C - 2);
		else
			temp.speed = temp.speed % (2 * R - 2);
		if(temp.dir > 2 && temp.c == 1) temp.dir = 3;
		else if(temp.dir > 2 && temp.c == C) temp.dir = 4;
		else if(temp.dir < 3 && temp.r == 1) temp.dir = 2;
		else if(temp.dir < 3 && temp.r == R) temp.dir = 1;
		shark.push_back(temp);
	}

	ans = 0;
	for (int col = 1; col <= C; col++) {
		fish(col);
		// cout << endl;
		// for (int i = 1; i <= R; i++) {
		// 	for (int j = 1; j <= C; j++) {
		// 		cout << setw(3) << map[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }
		if (col == C) break;
		memset(map, -1, sizeof(map));
		move();
	}
	cout << ans;
	return 0;
}
