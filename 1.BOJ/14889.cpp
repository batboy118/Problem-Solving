#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int N;
int a[22][22];
int visit[20];
vector <int> v1;
vector <int> v2;
int ans = INT_MAX;

void solve(int depth, int k) {
	if (depth == N / 2) {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < N; i++) {
			if (visit[i]) v1.push_back(i);
			else v2.push_back(i);
		}
		for (int i = 0; i < v1.size(); i++) {
			for (int j = 0; j < v1.size(); j++) {
				sum1 += a[v1[i]][v1[j]];
			}
		}
		for (int i = 0; i < v2.size(); i++) {
			for (int j = 0; j < v2.size(); j++) {
				sum2 += a[v2[i]][v2[j]];
			}
		}
		v1.clear();
		v2.clear();
		int gap = abs(sum1 - sum2);
		if (gap < ans) ans = gap;
		if (ans == 0) {
			cout << 0;
			exit(0);
		}
		return;
	}
	for (int i = k; i <= N / 2 + depth; i++) {
		visit[i] = 1;
		solve(depth + 1, i + 1);
		visit[i] = 0;
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N;
	v1.reserve(20);
	v2.reserve(20);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	visit[0] = 1;
	solve(1, 1);
	cout << ans;
	return 0;
}
