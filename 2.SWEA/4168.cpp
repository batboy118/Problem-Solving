#include<iostream>

using namespace std;
int N;

int S[25][2];
int total;
int ans;
int temp;
int sel;
int T;

void solve(int depth, int check) {
	if (T < total) {
		return;
	}
	if (depth >= N) {
		if (ans < temp) {
			sel = check;
			ans = temp;
		}
		return;
	}
	temp += S[depth][1];
	total += S[depth][0];
	solve(depth + 1, check | (1 << depth));
	temp -= S[depth][1];
	total -= S[depth][0];
	solve(depth + 1, check);
}

int main(int argc, char** argv) {
	int test_case;
	int TC;
	//freopen("input.txt", "r", stdin);
	cin >> TC;
	for (test_case = 1; test_case <= TC; ++test_case)
	{
		sel = 0;
		ans = 0;
		cin >> T >> N;
		for (int i = 0; i < N; i++) {
			cin >> S[i][0] >> S[i][1];
		}
		solve(0, 0);
		cout << '#' << test_case << ' ';
		for (int j = 0; j < N; j++) {
			if ((1 << j) & sel) {
				cout << j << ' ';
			}
		}
		cout << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
