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
int order[9];
int info[50][9];
int ans = 0;

void solve() {
	int out = 0;
	int score = 0;
	int position[8] = { 1, 0, 0, 0, 0, 0, 0 };
	int player = 0;
	for (int ining = 0; ining < N; ining++) {
		while (out < 3) {
			if (info[ining][order[player]]) {
				int offset = info[ining][order[player]];
				for (int i = 3; i > -1; i--) {
					position[i + offset] = position[i];
				}
				for (int i = 1; i < offset; i++) {
					position[i] = 0;
				}
				for (int i = 4; i < 4 + offset; i++) {
					score += position[i];
					position[i] = 0;
				}
			}
			else{
				out++;
			}
			player = (player + 1) % 9;
		}
		for (int i = 1; i < 8; i++) {
			position[i] = 0;
		}
		out = 0;
	}
	if (score > ans)
		ans = score;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> info[i][j];
		}
	}
	int permu[8] = { 1,2,3,4,5,6,7,8 };
	order[3] = 0;
	do {
		for (int i = 0; i < 8; i++) {
			if (i < 3) {
				order[i] = permu[i];
			}
			else {
				order[i + 1] = permu[i];
			}
		}
		solve();
	} while (next_permutation(permu, permu + 8));
	cout << ans;
	return 0;
}
