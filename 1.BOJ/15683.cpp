#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int N, M;
int map[10][10];
int copyMap[10][10];

struct info {
	int x, y;
	int num;
	int cnt;
	int check[4];
	int dir[4];
};
int ans = 1234567890;
int total;
vector<info> cctv;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void simulation() {
	int temp = total;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map[i][j] = copyMap[i][j];
		}
	}
	for (int i = 0; i < cctv.size(); i++) {
		int x = cctv[i].x;
		int y = cctv[i].y;
		for (int d = 0; d < 4; d++) {
			if (cctv[i].dir[d]) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				while (nx > 0 && nx <= M && ny > 0 && ny <= N && map[ny][nx] != 6) {
					if (map[ny][nx] == 0) {
						temp--;
						map[ny][nx] = 7;
					}
					nx = nx + dx[d];
					ny = ny + dy[d];
				}
			}
		}
	}
	if (ans > temp) {
		ans = temp;
	}
}

void solve(int depth) {
	if (depth == cctv.size()) {
		simulation();
		return;
	}
	for (int i = 0; i < cctv[depth].cnt; i++) {
		for (int d = 0; d < 4; d++) {
			cctv[depth].dir[d] = cctv[depth].check[(d + i) % 4];
		}
		solve(depth + 1);
	}
}

int main() {
	cin >> N >> M;
	total = N * M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++){
			cin>> copyMap[i][j];
			if (copyMap[i][j] != 0) total--;
			if (copyMap[i][j] > 0 && copyMap[i][j] < 6) {
				info temp;
				temp.x = j;
				temp.y = i;
				temp.num = copyMap[i][j];
				if (temp.num == 1) {
					temp.cnt = 4;
					temp.check[0] = 1;
					temp.check[1] = 0; temp.check[2] = 0; temp.check[3] = 0;
				}
				else if (temp.num == 3) {
					temp.cnt = 4;
					temp.check[0] = 1; temp.check[1] = 1;
					temp.check[2] = 0; temp.check[3] = 0;
				}
				else if (temp.num == 4) {
					temp.cnt = 4;
					temp.check[0] = 1; temp.check[1] = 1; temp.check[2] = 1;
					temp.check[3] = 0;
				}
				else if (temp.num == 2) {
					temp.cnt = 2;
					temp.check[0] = 1; temp.check[2] = 1;
					temp.check[1] = 0; temp.check[3] = 0;
				}
				else {
					temp.cnt = 1;
					temp.check[0] = 1; temp.check[1] = 1; temp.check[2] = 1; temp.check[3] = 1;
				}
				cctv.push_back(temp);
			}
		}
	}
	solve(0);
	cout << ans;
	return 0;
}
