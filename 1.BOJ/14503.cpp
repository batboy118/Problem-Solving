#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int N, M;
int map[51][51];
int ans;
int x, y, d;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void solve() {
	map[y][x] = -1;
	ans++;
	while (1) {
		int flag = 0;
		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (map[ny][nx] == 0) {
				y = ny;
				x = nx;
				map[y][x] = -1;
				ans++;
				flag = 1;
				break;
			}
		}
		if (flag) {
			continue;
		}
		else {
			y = y - dy[d];
			x = x - dx[d];
			if (map[y][x] == 1) break;
			else continue;
		}
	}
}

int main() {
	cin >> N >> M;
	cin >> y >> x >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}
	solve();
	cout << ans ;
	return 0;
}
