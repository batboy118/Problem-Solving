#include<iostream>
#define MAX_D 13
#define MAX_W 20
using namespace std;

bool map[MAX_D][MAX_W];
bool copymap[MAX_D][MAX_W];
int D,W,K;
int result;
int Chemical[MAX_D];

void copy() {
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			copymap[i][j] = map[i][j];
		}
	}
}

bool check(int cnt) {

	bool OK = true;

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < W; j++) {
			copymap[Chemical[i]][j] |= 1;
		}
	}

	for (int i = 0; i < W; i++) {
		int countA = 0;
		int countB = 0;
		for (int j = 0; j < D; j++) {
			if (copymap[j][i]) {
				countA++;
				countB = 0;
			}
			else {
				countA=0;
				countB ++;
			}
			if (countA >= K || countB >= K) {
				break;
			}

		}
		if (countA < K && countB < K) {
			OK = false;
			break;
		}
	}

	if (OK) return OK;

	OK = true;

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < W; j++) {
			copymap[Chemical[i]][j] &= 0;
		}
	}

	for (int i = 0; i < W; i++) {
		int countA = 0;
		int countB = 0;
		for (int j = 0; j < D; j++) {
			if (copymap[j][i]) {
				countA++;
				countB = 0;
			}
			else {
				countA = 0;
				countB++;
			}
			if (countA >= K || countB >= K) {
				break;
			}

		}
		if (countA < K && countB < K) {
			OK = false;
			break;
		}
	}

	return OK;
}

void solve() {

	
	//Powerset
	for (int i = 0; i < (1 << D); i++) {
		int cnt = 0;
		for (int j = 0; j < D; j++) {
			if ((1 << j) & i) {
				Chemical[cnt] = j;
				cnt++;
			}
		}
		if (cnt > result) { continue; }
		copy();
		bool ok = check(cnt);
		copy();
		if (ok && result>cnt) result = cnt;
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//freopen("input.txt", "r", stdin);

	int T;

	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}
		result = 987654321;
		solve();

		cout << '#' << test_case << ' ' << result<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}