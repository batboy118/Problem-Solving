#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <string.h>

using namespace std;

int N;
int ans = INT_MAX;
vector<int> g[10];
int p[10];
int comb[10];
int s1[10];
int s2[10];
int check[10];

int check_valid() {
	memset(check, 0, sizeof(check));
	queue <int> q;
	for (int i = 0; i < N; i++) {
		if (s1[i]) {
			q.push(i);
			check[i] = 1;
			break;
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		int len = q.size();
		q.pop();
		while (len--) {
			for (int i = 0; i < g[cur].size(); i++) {
				int next = g[cur][i];
				if (check[next] || s1[next] == 0) continue;
				check[next] = 1;
				q.push(next);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (s2[i]) {
			q.push(i);
			check[i] = 1;
			break;
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		int len = q.size();
		q.pop();
		while (len--) {
			for (int i = 0; i < g[cur].size(); i++) {
				int next = g[cur][i];
				if (check[next] || s2[next] == 0) continue;
				check[next] = 1;
				q.push(next);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (check[i] == 0) return 0;
	}
	return 1;
}

int get_diff() {
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < N; i++) {
		if (s1[i]) sum1 += p[i];
		else sum2 += p[i];
	}
	return abs(sum1 - sum2);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < N; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int temp;
			cin >> temp;
			g[i].push_back(temp - 1);
		}
	}
	for (int i = 0; i < N - 1; i++) {
		s2[N - 1] = 1;
		s1[N - 1] = 0;
		for (int j = 0; j < N - 1; j++) {
			if (i < j) comb[j] = 1;
			else comb[j] = 0;
		}
		do {
			for (int j = 0; j < N - 1; j++) {
				if (comb[j]) {
					s2[j] = 1;
					s1[j] = 0;
				}
				else {
					s1[j] = 1;
					s2[j] = 0;
				}
			}
			if (check_valid()) {
				int diff = get_diff();
				if (diff < ans) {
					ans = diff;
				}
			}
		} while (next_permutation(comb, comb + N - 1));
	}
	if (ans == INT_MAX) cout << -1;
	else cout << ans;
	return 0;
}
