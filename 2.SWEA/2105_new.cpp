#include<iostream>
#include<string.h>

using namespace std;

int N;
int map[22][22];
int dx[] = { 1, 1, -1, -1 };
int dy[] = { -1, 1, 1, -1 };
int check[101];
int ans = 0;

void check_route(int x, int y, int x1, int x2, int x3, int y1, int y2, int y3) {
	memset(check, 0, sizeof(check));
	int r = y, c = x;
	int cnt = 0;
	while (c != x1) {
		r += dy[0];
		c += dx[0];
		if (check[map[r][c]] == 1) return;
		check[map[r][c]] = 1;
		cnt++;
	}
	while (c != x2) {
		r += dy[1];
		c += dx[1];
		if (check[map[r][c]] == 1) return;
		check[map[r][c]] = 1;
		cnt++;
	}
	while (c != x3) {
		r += dy[2];
		c += dx[2];
		if (check[map[r][c]] == 1) return;
		check[map[r][c]] = 1;
		cnt++;
	}
	while (c != x) {
		r += dy[3];
		c += dx[3];
		if (check[map[r][c]] == 1) return;
		check[map[r][c]] = 1;
		cnt++;
	}
	if (ans < cnt)
		ans = cnt;
}

void solve() {
	for (int y = 1; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int cnt1 = 1;
			int nx1, ny1, nx2, ny2, nx3, ny3;
			nx1 = x + dx[0] * cnt1;
			ny1 = y + dy[0] * cnt1;
			while (nx1 > -1 && ny1 > -1 && nx1 < N && ny1 < N) {
				int cnt2 = 1;
				nx2 = nx1 + dx[1] * cnt2;
				ny2 = ny1 + dy[1] * cnt2;
				nx3 = nx2 + dx[2] * cnt1;
				ny3 = ny2 + dy[2] * cnt1;
				while (nx2 > -1 && ny2 > -1 && nx2 < N && ny2 < N
						&& nx3 > -1 && ny3 > -1 && nx3 < N && ny3 < N) {
					check_route(x, y, nx1, nx2, nx3, ny1, ny2, ny3);
					cnt2++;
					nx2 = nx1 + dx[1] * cnt2;
					ny2 = ny1 + dy[1] * cnt2;
					nx3 = nx2 + dx[2] * cnt1;
					ny3 = ny2 + dy[2] * cnt1;
				}
				cnt1++;
				nx1 = x + dx[0] * cnt1;
				ny1 = y + dy[0] * cnt1;
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++){
				cin >> map[i][j];
			}
		}
		ans = -1;
		solve();
		cout <<'#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
