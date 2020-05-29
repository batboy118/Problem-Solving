#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;

int N, M, H;
int map[32][12];

int simulation() {
	for (int j = 1; j <= N; j++) {
		int pos = j;
		for (int i = 1; i <= H; i++) {
			if (map[i][pos - 1] == 1) {
				pos--;
			}
			else if (map[i][pos] == 1) {
				pos++;
			}
		}
		if (pos != j)	return 0;
	}
	return 1;
}

void sel(int depth, int k, int until) {
	if (depth == until) {
		if (simulation()) {
			cout << until;
			exit(0);
		}
		return;
	}
	for (int j = k; j - depth < N + 1 - until ; j++) {
		for (int i = 1; i <= H; i++) {
			if (map[i][j] == 0 && map[i][j-1] ==0 && map[i][j + 1] == 0){
				map[i][j] = 1;
				sel(depth + 1, k + 1, until);
				map[i][j] = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> H;
	while(M--) {
		int i, j;
		cin >> i >> j;
		map[i][j] = 1;
	}

	for (int i = 0; i < 4; i++) {
		sel(0, 1, i);
	}
	cout << -1;
	return 0;
}
