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
int total;
int ans = INT_MIN;

void solve(int cur) {
	if (cur >= N) {
		if (total > ans) ans = total;
		return;
	}
	for (int i = cur; i < N; i++) {
		if(i + T[i] <= N) total += P[i];
		solve(i + T[i]);
		if (i + T[i] <= N) total -= P[i];
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> T[i] >> P[i];
	solve(0);
	cout << ans;
	return 0;
}
