#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int paper[10][10];
int sticker[6];
int ans = INT_MAX;
int cnt;

int is_clear() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (paper[i][j]) return 0;
		}
	}
	return 1;
}
int can_paste(int y, int x, int s) {
	if (y + s > 10 || x + s > 10) return 0;
	for (int i = y; i < y + s; i++) {
		for (int j = x; j < x + s; j++) {
			if (paper[i][j] == 0) return 0;
		}
	}
	return 1;
}

void update(int y, int x, int s, int val) {
	for (int i = y; i < y + s; i++) {
		for (int j = x; j < x + s; j++) {
			paper[i][j] = val;
		}
	}
}

void solve(int y, int x) {
	if (x == 10) {
		y++;
		x = 0;
	}
	if (y == 10) {
		if (is_clear()) {
			if (cnt < ans) ans = cnt;
		}
		return;
	}
	if (cnt >= ans) return;
	if (paper[y][x]) {
		for (int s = 5; s > 0; s--) {
			if (sticker[s] < 5 && can_paste(y, x, s)) {
				sticker[s]++;
				update(y, x, s, 0);
				cnt++;
				solve(y, x + 1);
				cnt--;
				update(y, x, s, 1);
				sticker[s]--;
			}
		}
	}
	else {
		solve(y, x + 1);
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> paper[i][j];
		}
	}
	solve(0, 0);
	if (ans == INT_MAX) cout << -1;
	else cout << ans;
	return 0;
}
