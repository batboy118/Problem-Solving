#include<iostream>
#include<string.h>

using namespace std;

int D, W, K;
int cell[13][20];
int cp[13][20];
int ans;
int A[13];
int B[13];

int check() {
	for (int i = 0; i < D; i++) {
		if (A[i]) {
			for (int j = 0; j < W; j++) {
				cell[i][j] = 0;
			}
		}
		else if (B[i]) {
			for (int j = 0; j < W; j++) {
				cell[i][j] = 1;
			}
		}
	}
	for (int j = 0; j < W; j++) {
		int cnt = 1;
		for (int i = 0; i < D - 1; i++) {
			if (cell[i][j] == cell[i + 1][j]) {
				cnt++;
				if (cnt >= K) {
					break;
				}
			}
			else { cnt = 1; }
		}
		if (cnt < K) {
			return 0;
		}
	}
	return 1;
}

void solve(int depth, int cnt) {
	if (cnt >= ans || depth > D) return;
	if (depth == D) {
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cell[i][j] = cp[i][j];
			}
		}
		if (check()) {
			ans = cnt;
			return;
		}
	}
	solve(depth + 1, cnt);
	A[depth] = 1;
	solve(depth + 1, cnt + 1);
	A[depth] = 0;
	B[depth] = 1;
	solve(depth + 1, cnt + 1);
	B[depth] = 0;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> cp[i][j];
			}
		}
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		ans = 987654321;
		solve(0, 0);
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
