#include<iostream>
#include<string.h>
#include<limits.h>
#include<queue>

using namespace std;
int N , W, H;
int order[12];
int cp[15][12];
int map[15][12];
int ans = INT_MAX;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int visit[15][12];

void move_down() {
	for (int j = 0; j < W; j++) {
		for (int i = H - 1; i > -1; i--) {
			if (map[i][j] == 0)break;
			else if (map[i][j] == -1) {
				int k = i;
				while (k > 0 && map[k - 1][j]) {
					map[k][j] = map[k - 1][j];
					k--;
				}
				map[k][j] = 0;
				i++;
			}
		}
	}
}

void simulation() {
	queue <pair<int, int> > q;
	for (int i = 0; i < N; i++) {
		memset(visit, 0, sizeof(visit));
		int j;
		for (j = 0; j < H; j++ ) {
			if (map[j][order[i]]) break;
		}
		if (j == H) return;
		q.push(make_pair(j, order[i]));
		visit[j][order[i]] = 1;
		while (!q.empty()) {
			int len = q.size();
			while(len--){
				int y = q.front().first;
				int x = q.front().second;
				int val = map[y][x];
				map[y][x] = -1;
				q.pop();
				for (int d = 0; d < 4; d++) {
					int ny = y, nx = x;
					for (int s = 1; s < val; s++) {
						ny += dy[d];
						nx += dx[d];
						if (ny >= H || ny < 0 || nx >= W || nx < 0) break;
						if (map[ny][nx] > 1 && visit[ny][nx] == 0) {
							q.push(make_pair(ny, nx));
							visit[ny][nx] = 1;
						}
						else if (map[ny][nx] == 1) map[ny][nx] = -1;
					}
				}
			}
		}
		move_down();
	}
}

void solve(int depth) {
	if (ans == 0) return;
	if (depth == N) {
		memcpy(map, cp, sizeof(cp));
		simulation();
		int cnt = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j]) cnt++;
			}
		}
		if (cnt < ans) ans = cnt;
		return;
	}
	for (int i = 0; i < W; i++) {
		order[depth] = i;
		solve(depth + 1);
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
		cin >> N >> W >> H;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> cp[i][j];
			}
		}
		ans = INT_MAX;
		solve(0);
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
