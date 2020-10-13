#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

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

struct Fish {
	int dir;
	int x, y;
	int is_dead;
};

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int nd[] = { 1, 2, 3, 4, 5, 6, 7, 0 };

int board[4][4];
Fish fish[17];
Fish shark;
int cnt = 0;

int isEdge(int y, int x) {
	return y < 0 || x < 0 || y >3 || x> 3;
}

void move(Fish fish[], int board[][4]) {
	for (int i = 1; i <= 16; i++) {
		Fish& f = fish[i];
		if (f.is_dead) continue;
		int ny = f.y + dy[f.dir];
		int nx = f.x + dx[f.dir];
		while (isEdge(ny, nx) || board[ny][nx] == -1) {
			f.dir = nd[f.dir];
			ny = f.y + dy[f.dir];
			nx = f.x + dx[f.dir];
		}
		int target = board[ny][nx];
		board[ny][nx] = i;
		board[f.y][f.x] = target;
		fish[target].y = f.y;
		fish[target].x = f.x;
		f.y = ny;
		f.x = nx;
	}
}

void dfs(int depth, int sum, Fish fish[], Fish& shark, int board[][4]) {
	PRINT_ARR2(4, 4, board[i][j]);

	int newBoard[4][4];
	move(fish, board);
	PRINT_ARR2(4, 4, board[i][j]);

	//for (int i = 1; i <= 4; i++) {
	//	int ny = shark.y + dy[shark.dir] * i;
	//	int nx = shark.x + dx[shark.dir] * i;
	//	if (isEdge(ny, nx)) {
	//		if (sum > cnt) cnt = sum;
	//		return;
	//	}

	//	if(board)
	//}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> board[i][j];
			cin >> fish[board[i][j]].dir;
			fish[board[i][j]].y = i;
			fish[board[i][j]].x = j;
			fish[board[i][j]].dir--;
		}
	}
	shark.x = 0;
	shark.y = 0;
	shark.dir = fish[board[0][0]].dir;
	fish[board[0][0]].is_dead = 1;
	cnt = board[0][0];
	board[0][0] = -1; //상어 -1
	dfs(0, cnt, fish, shark, board);
	cout << cnt;
	return 0;
}
