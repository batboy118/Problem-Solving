#include <iostream>
#include <queue>
#include <algorithm>
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
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;
int dy[] = {0,0,-1,1};
int dx[] = {1,-1,0,0};
int dd[] = {1,0,3,2};

struct MAL {
	int isDead;
	int x, y, dir;
};

struct LAND{
	int color;
	vector<int> mal;
};

int N, K;
MAL mal[10];
LAND board[12][12];

int isEdge(int y, int x) {
	return y < 0 || x < 0 || y >= N || x >= N;
}

int solve() {
	for (int i = 0; i < K; i++) {
		MAL& m = mal[i];
		int y = m.y;
		int x = m.x;
		int ny = y + dy[m.dir];
		int nx = x + dx[m.dir];
		if (isEdge(ny,nx) || board[ny][nx].color == BLUE) {
			m.dir = dd[m.dir];
			ny = y + dy[m.dir];
			nx = x + dx[m.dir];
		}
		if (isEdge(ny, nx) || board[ny][nx].color == BLUE) {
			continue;
		}
		if (board[ny][nx].color == WHITE) {
			int size = board[y][x].mal.size();
			int idx = find(board[y][x].mal.begin(), board[y][x].mal.end(), i) - board[y][x].mal.begin();
			for (int k = idx; k < size; k++) {
				int target = board[y][x].mal[k];
				board[ny][nx].mal.push_back(target);
				mal[target].y = ny;
				mal[target].x = nx;
			}
			for (int k = idx; k < size; k++) {
				board[y][x].mal.pop_back();
			}
			if (board[ny][nx].mal.size() >= 4) return 1;
			continue;
		}
		if (board[ny][nx].color == RED) {
			int size = board[y][x].mal.size();
			int idx = find(board[y][x].mal.begin(), board[y][x].mal.end(), i) - board[y][x].mal.begin();
			for (int k = size - 1; k >= idx; k--) {
				int target = board[y][x].mal[k];
				board[ny][nx].mal.push_back(target);
				board[y][x].mal.pop_back();
				mal[target].y = ny;
				mal[target].x = nx;
			}
			if (board[ny][nx].mal.size() >= 4) return 1;
			continue;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j].color;
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> mal[i].y >> mal[i].x >> mal[i].dir;
		mal[i].dir--;
		mal[i].y--;
		mal[i].x--;
		board[mal[i].y][mal[i].x].mal.push_back(i);
	}
	int turn = 0;

	//PRINT_ARR2(N, N, board[i][j].mal.size());
	//cout << "-----------------------------" << endl;
	while (turn <= 1000) {
		turn++;
		if (solve()) break;
		//PRINT_ARR2(N, N, board[i][j].mal.size());
		//cout << "-----------------------------" << endl;

	}
	if (turn > 1000) cout << -1;
	else cout << turn;
	return 0;
}
