#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
using namespace std;
int N, L, R;
int a[52][52];
int check[52][52];
int ans;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 ,0 };

int solve() {
	int Rval = 0;
	vector < pair <int, int> > temp;
	queue < pair <int, int> > q;
	temp.reserve(55*55);
	memset(check, 0, sizeof(check));
	for (int i = 0; i < N; i++) {
		for (int j = (i + 1) % 2; j < N; j += 2) {
			if (check[i][j]) continue;
			int total = a[i][j];
			q.push(make_pair(i, j));
			temp.push_back(make_pair(i, j));
			check[i][j] = 1;
			while (!q.empty()) {
				int len = q.size();
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				while (len--) {
					for (int d = 0; d < 4; d++) {
						int ny = y + dy[d];
						int nx = x + dx[d];
						if (nx < 0 || ny < 0 || ny >= N || nx >= N || check[ny][nx]) continue;
						int gap = abs(a[y][x] - a[ny][nx]);
						if (gap >= L && gap <= R) {
							q.push(make_pair(ny, nx));
							temp.push_back(make_pair(ny, nx));
							check[ny][nx] = 1;
							total += a[ny][nx];
						}
					}
				}
			}
			if (temp.size() > 1) {
				Rval = 1;
				int setVal = total / temp.size();
				for (int i = 0; i < temp.size(); i++) {
					int y = temp[i].first;
					int x = temp[i].second;
					a[y][x] = setVal;
				}
				temp.clear();
			}
			else {
				temp.pop_back();
			}
		}
	}
	return Rval;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	while (solve()) {
		ans++;
	}
	cout << ans;
	return 0;
}
