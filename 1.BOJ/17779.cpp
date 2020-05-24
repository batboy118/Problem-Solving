#include <iostream>
#include <limits.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int A[23][23];
int ans = INT_MAX;
int x, y, d1, d2;
int cp[5];
int lr[4][2];
int lc[4][2];
int check[23][23];

void check_line() {
	for (int t = 0; t <= d1; t++) {
		check[y + t][x - t] = 9;
		check[y + d2 + t][x + d2 - t ] = 9;
	}
	for (int t = 0; t <= d2; t++) {
		check[y + t][x + t] = 9;
		check[y + d1 + t][x - d1 + t] = 9;
	}
	cp[4] = A[y][x];
	cp[4] += A[y + d1 + d2][x - d1 + d2];
	for (int i = y + 1; i < y + d1 + d2; i++) {
		for (int j = x - d1; j <= x + d2; j++) {
			if (check[i][j] == 9) {
				cp[4]+=A[i][j];
				while (check[i][j + 1] != 9) {
					j++;
					cp[4] += A[i][j];
					check[i][j] = 9;
				}
				cp[4] += A[i][j + 1];
				break;
			}
		}
	}
}

void get1to5() {
	check_line();

	lr[0][0] = 1, lr[0][1] = y + d1 - 1;
	lr[1][0] = 1, lr[1][1] = y + d2;
	lr[2][0] = y + d1, lr[2][1] = N;
	lr[3][0] = y + d2 + 1, lr[3][1] = N;

	lc[0][0] = 1, lc[0][1] = x;
	lc[1][0] = x + 1, lc[1][1] = N;
	lc[2][0] = 1, lc[2][1] = x - d1 + d2 - 1;
	lc[3][0] = x - d1 + d2, lc[3][1] = N;

	int cnt = -1;
	while (++cnt < 4) {
		for (int r = lr[cnt][0]; r <= lr[cnt][1]; r++) {
			for (int c = lc[cnt][0]; c <= lc[cnt][1]; c++) {
				if (check[r][c] == 0) {
					cp[cnt] += A[r][c];
				}
			}
		}
	}
}

int solve() {
		get1to5();;
		sort(cp, cp + 5);
	return cp[4] - cp[0];
}

void select_xy() {
	x = 0;
	while (++x <= N) {
		y = 0;
		while (++y <= N) {
			d1 = 1;
			d2 = 1;
			while (y + d1 + d2 <= N && x - d1 >= 1 && x + d2 <= N)
			{
				while (x - d1 >= 1 && x + d2 <= N && y + d1 + d2 <= N)
				{
					memset(check, 0, sizeof(check));
					memset(cp, 0, sizeof(cp));
					int temp = solve();
					if (temp < ans)
						ans = temp;
					d2++;
				}
				d2 = 1;
				d1++;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	select_xy();
	cout << ans;
}
