#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int N;
int map[16][16];
int ans = 0;

void solve(int x, int y, int dir) {
	if (x == N - 1 && y == N - 1) {
		ans++;
		return;
	}
	if (dir == 0) {
		if(x + 1 < N && map[y][x+ 1] != 1) solve(x + 1, y, 0);
		if (x + 1 < N && y + 1 < N && map[y + 1][x + 1] != 1 && map[y + 1][x] != 1 && map[y][x + 1] != 1) solve(x + 1, y + 1, 1);
	}
	else if (dir == 1) {
		if (y + 1 < N && map[y + 1][x] != 1) solve(x, y + 1, 2);
		if (x + 1 < N && y + 1 < N && map[y + 1][x + 1] != 1 && map[y + 1][x] != 1 && map[y][x + 1] != 1) solve(x + 1, y + 1, 1);
		if (x + 1 < N && map[y][x + 1] != 1) solve(x + 1, y, 0);
	}
	else {
		if (x + 1 < N && y + 1 < N && map[y + 1][x + 1] != 1 && map[y + 1][x] != 1 && map[y][x + 1] != 1) solve(x + 1, y + 1, 1);
		if (y + 1 < N && map[y + 1][x] != 1) solve(x, y + 1, 2);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
	solve(1, 0, 0);
	cout << ans;
	return 0;
}
