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
char m[12][12];
int R[2];
int B[2];
int dx[4] = { 1,0,-1, 0 };
int dy[4] = { 0,-1,0,1 };
int ans = 11;
int moves[12];

void move() {
	int rx = R[1];
	int ry = R[0];
	int bx = B[1];
	int by = B[0];
	int Rflag = 0;
	for (int i = 0; i < ans - 1; i++) {
		int d = moves[i];
		int rnx = rx + dx[d];
		int rny = ry + dy[d];
		while (m[rny][rnx] != '#') {
			if (m[rny][rnx] == 'O') {
				Rflag = 1;
				break;
			}
			rnx = rnx + dx[d];
			rny = rny + dy[d];
		}
		int bnx = bx + dx[d];
		int bny = by + dy[d];
		while (m[bny][bnx] != '#') {
			if (m[bny][bnx] == 'O') {
				return;
			}
			bnx = bnx + dx[d];
			bny = bny + dy[d];
		}
		if (Rflag) {
			ans = i + 1;
			return;
		}
		rnx -= dx[d]; rny -= dy[d];
		bny -= dy[d], bnx -= dx[d];
		if (rnx == bnx && rny == bny) {
			if (abs(rx - rnx) + abs(ry - rny) > abs(bx - bnx) + abs(by - bny)) {
				rnx -= dx[d]; rny -= dy[d];
			}
			else {
				bny -= dy[d], bnx -= dx[d];
			}
		}
		rx = rnx; ry = rny;
		bx = bnx; by = bny;
	}
}

void solve(int depth) {
	if (ans <= depth) return;
	if (depth >= ans - 1) {
		move();
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (depth > 0 && moves[depth - 1] == i) continue;
		if (depth > 1 && moves[depth - 2] == i && moves[depth - 1] == (i + 2) % 4) continue;
		moves[depth] = i;
		solve(depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> m[i][j];
			if (m[i][j] == 'R') {
				R[0] = i;
				R[1] = j;
				m[i][j] = '.';
			}
			else if (m[i][j] == 'B') {
				B[0] = i;
				B[1] = j;
				m[i][j] = '.';
			}
		}
	}
	solve(0);
	if (ans == 11) cout << -1;
	else cout << ans;
	return 0;
}
