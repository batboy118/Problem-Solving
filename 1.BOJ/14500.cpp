#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int N, M;
int p[500][500];
int visit[500][500];
int temp;
int ans;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void solve(int depth, int y, int x) {
	if (depth == 4) {
		if (temp > ans) {
			ans = temp;
		}
		return;
	}
	for (int i = 0; i < 3; i++) { //3가지 방향만 해도 된다.
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > -1 && ny > -1 && nx < M && ny < N && !visit[ny][nx]) {
			visit[ny][nx] = 1;
			temp += p[ny][nx];
			solve(depth + 1, ny, nx);
			temp -= p[ny][nx];
			visit[ny][nx] = 0;
		}
	}
}

//모자 모양 처리
void solve2(int y, int x) {
	for (int j = 0; j < 4; j++) {
		int flag = 1;
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[(j + i) % 4];
			int ny = y + dy[(j + i) % 4];
			if (nx > -1 && ny > -1 && nx < M && ny < N) {
				temp += p[ny][nx];
			}
			else {
				for (int k = 0; k < i; k++) {
					int nxx = x + dx[(j + k) % 4];
					int nyy = y + dy[(j + k) % 4];
					temp -= p[nyy][nxx];
				}
				flag = 0;
				break;
			}
		}
		if (flag) {
			if (temp > ans) {
				ans = temp;
			}
			for (int i = 0; i < 3; i++) {
				int nx = x + dx[(j + i) % 4];
				int ny = y + dy[(j + i) % 4];
				temp -= p[ny][nx];
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> p[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 1;
			temp += p[i][j];
			solve(1, i, j);
			solve2(i, j);
			temp -= p[i][j];
			visit[i][j] = 0;
		}
	}
	cout << ans;
	return 0;
}
