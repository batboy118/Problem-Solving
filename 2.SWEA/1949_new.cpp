#include<iostream>

using namespace std;

int ans;
int N, K;
int map[8][8];
int visit[8][8];
int cnt;
int maxVal;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int check;
struct info
{
	int x, y;
};
info point[5];

void solve(int depth, int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || nx >= N || ny >= N || visit[ny][nx] || (check && map[y][x] <= map[ny][nx]) || (map[ny][nx] - K >= map[y][x])) {
			if (ans < depth) {
				ans = depth;
			}
			continue;
		}
		if (map[ny][nx] >= map[y][x]) {
				int tmp = map[ny][nx];
				check = 1;
				visit[ny][nx] = 1;
				map[ny][nx] = map[y][x] - 1;
				solve(depth + 1, ny, nx);
				map[ny][nx] = tmp;
				visit[ny][nx] = 0;
				check = 0;
				k--;
		}
		else {
			visit[ny][nx] = 1;
			solve(depth + 1, ny, nx);
			visit[ny][nx] = 0;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cnt = 0;
		maxVal = 0;
		ans = 0;
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (maxVal < map[i][j]) maxVal = map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(map[i][j] == maxVal){
					point[cnt].y = i;
					point[cnt].x = j;
					cnt++;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = 0;
			}
		}
		for (int i = 0; i < cnt; i++) {
			check = 0;
			visit[point[i].y][point[i].x] = 1;
			solve(1, point[i].y, point[i].x);
			visit[point[i].y][point[i].x] = 0;
		}
		cout << "#" << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
