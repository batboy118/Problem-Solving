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

int N, M;
char m[1002][1002];
queue <pair<int, int > > q;
queue <pair<int, int> > p;
int ans;
int moves[12];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void solve() {
	if (p.front().first == 0 || p.front().second == 0 || p.front().second == M - 1 || p.front().first == N - 1) {
		ans = 1;
		return;
	}
	int cnt = 1;
	int flag = 0;
	while (!p.empty()) {
		int plen = p.size();
		int qlen = q.size();
		cnt++;
		while (qlen--) {
			int qy = q.front().first;
			int qx = q.front().second;
			q.pop();
			for (int d = 0; d < 4; d++) {
				int nqy = qy + dy[d];
				int nqx = qx + dx[d];
				if (nqy > -1 && nqy < N && nqx > -1 && nqx < M && m[nqy][nqx] != '#' && m[nqy][nqx] != '*') {
					m[nqy][nqx] = '*';
					q.push(make_pair(nqy, nqx));
				}
			}
		}

		while (plen--) {
			int py = p.front().first;
			int px = p.front().second;
			p.pop();
			for (int d = 0; d < 4; d++) {
				int npy = py + dy[d];
				int npx = px + dx[d];
				if ((npy == 0 || npx == 0 || npx == M - 1 || npy == N - 1) && m[npy][npx] == '.') {
					flag = 1;
					break;
				}
				if (m[npy][npx] != '#' && m[npy][npx] != '*' && m[npy][npx] != '@') {
					m[npy][npx] = '@';
					p.push(make_pair(npy, npx));
				}
			}
		}
		if (flag) {
			if (cnt < ans) ans = cnt;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> M >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> m[i][j];
				if (m[i][j] == '*') {
					q.push(make_pair(i, j));
				}
				else if (m[i][j] == '@') {
					p.push(make_pair(i, j));
				}
			}
		}
		ans = INT_MAX;
		solve();
		while(!q.empty()) q.pop();
		while (!p.empty()) p.pop();
		if (ans == INT_MAX) cout << "IMPOSSIBLE\n";
		else cout << ans << '\n';
	}
	return 0;
}
