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

long long ans;
int N, B, C;
int cs[1000000];

void solve() {
	for (int i = 0; i < N; i++) {
		cs[i] -= B;
		if (cs[i] > 0) {
			int v = cs[i] / C;
			int m = cs[i] % C;
			if (m)
				ans += v + 1;
			else
				ans += v;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	ans = N;
	for (int i = 0; i < N; i++) {
		cin >> cs[i];
	}
	cin >> B >> C;
	solve();
	cout << ans;
	return 0;
}
