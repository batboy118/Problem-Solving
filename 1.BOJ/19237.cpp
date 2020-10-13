#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define PRINT_ARR(n, target) for(int i = 0; i < n; i++){ \
								cout << target << ' '; \
							} \
							cout <<'\n';\

#define PRINT_ARR2(n,m, target)	for(int i = 0; i < n; i++){ \
								for(int j = 0; j < m; j++){ \
									cout << target << ' '; \
								} \
								cout <<'\n';\
							}

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int cnt;



struct Shark {
	int y, x;
	int is_dead = 0;
	int dir;
	int p_dir[4][4];
};

struct Land {
	int shark = 0;
	int smell = 0;
	int time = 0;
};

int N, M, k;
int r;
Land board[20][20];
Shark sharks[404];

int is_edge(int y, int x) {
	return y < 0 || x < 0 || y >= N || x >= N;
}

void move() {
	for (int i = 1; i <= M; i++) {
		Shark& shark = sharks[i];
		if (shark.is_dead) continue;
		int cx = shark.x, cy = shark.y;
		int dir = shark.dir;
		int ny, nx;
		int found = 0;
		board[cy][cx].shark = 0;
		for (int j = 0; j < 4; j++) {
			int d = shark.p_dir[dir][j];
			ny = cy + dy[d];
			nx = cx + dx[d];
			if(is_edge(ny, nx)) continue;
			if (board[ny][nx].time == 0 || cnt - board[ny][nx].time > k) { //
				found = 1;
				if (board[ny][nx].shark > 0 && board[ny][nx].shark < i) {
					shark.is_dead = 1;
					r--;
					break;
				}
				board[ny][nx].shark = i;
				shark.y = ny;
				shark.x = nx;
				shark.dir = d;
				break;
			}
		}
		if (found) continue;
		for (int j = 0; j < 4; j++) {
			int d = shark.p_dir[dir][j];
			ny = cy + dy[d];
			nx = cx + dx[d];
			if (is_edge(ny, nx)) continue;
			if (board[ny][nx].smell == i) {
				found = 1;
				if (board[ny][nx].shark > 0 && board[ny][nx].shark < i) {
					shark.is_dead = 1;
					r--;
					break;
				}
				board[ny][nx].shark = i;
				shark.y = ny;
				shark.x = nx;
				shark.dir = d;
				break;
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		if (sharks[i].is_dead) continue;
		Shark& shark = sharks[i];
		board[shark.y][shark.x].time = cnt;
		board[shark.y][shark.x].smell = i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j].shark;
			if (board[i][j].shark) {
				sharks[board[i][j].shark].y = i;
				sharks[board[i][j].shark].x = j;
				board[i][j].smell = board[i][j].shark;
				board[i][j].time = 1;
			}
		}
	}
	r = M;
	for (int i = 1; i <= M; i++) {
		cin >> sharks[i].dir;
		sharks[i].dir--;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> sharks[i].p_dir[j][k];
				sharks[i].p_dir[j][k]--;
			}
		}
	}
	cnt = 1;
	//cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	//PRINT_ARR2(N,N, board[i][j].shark)
	while (r != 1 && cnt <= 1001) {
        cnt++;
		move();
		//cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		//PRINT_ARR2(N, N, board[i][j].shark)
	}
	if (cnt > 1001) cout << -1;
	else cout << --cnt;
	return 0;
}
