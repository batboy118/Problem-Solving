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

int N;
int T[15];
int P[15];
int dp[16];

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = i + T[i]; j <= N; j++) {
			dp[j] = max(dp[j], dp[i] + P[i]);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> T[i] >> P[i];
	solve();
	cout << dp[N];
	return 0;
}
