#include<iostream>
#include<queue>
#include<string.h>
#include<limits.h>

using namespace std;
int N;
int ans;
int map[15][15];
int visit[15][15];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int sy, sx, fy, fx;

void solve() {
	queue <pair<int, int> > q;
	int cnt = 0;
	q.push(make_pair(sy, sx));
	visit[sy][sx] = 1;
	while (!q.empty()) {
		int len = q.size();
		while (len--) {
			int x = q.front().second;
			int y = q.front().first;
			if (x == fx && y == fy) {
				ans = cnt;
				return;
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[ny][nx] == 1 || visit[ny][nx] == 1) continue;
				else if (map[ny][nx] == 0) {
					q.push(make_pair(ny, nx));
					visit[ny][nx] = 1;
				}
				else if (map[ny][nx] == 2 && cnt % 3 == 2) {
					q.push(make_pair(ny, nx));
					visit[ny][nx] = 1;
				}
				else if (map[ny][nx] == 2 && cnt % 3 != 2) q.push(make_pair(y, x));
			}
		}
		cnt++;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		}
		cin >> sy >> sx >> fy >> fx;
		ans = INT_MAX;
		memset(visit, 0, sizeof(visit));
		solve();
		if (ans == INT_MAX) ans = -1;
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
