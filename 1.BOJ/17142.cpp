#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

#define EMPTY 0
#define WALL 1
#define VIRUS 2
#define BOM 3

struct info{
	int x;
	int y;
} vloc[10];

int N, M;
int map[53][53];
int copyMap[53][53];
int ans = INT_MAX;
int vcnt = 0;
vector<int> sel;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int countBlack() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == EMPTY) {
				cnt++;
			}
		}
	}
	return cnt;
}

void move() {
	queue<info> q;
	for (vector<int>::iterator i = sel.begin(); i != sel.end(); i++) {
		map[vloc[*i].y][vloc[*i].x] = BOM;
		info temp;
		temp.y = vloc[*i].y;
		temp.x = vloc[*i].x;
		q.push(temp);
	}
	int cnt = 0;
	int flag = 0;
	int countEmpty = countBlack();
	if (countEmpty == 0) {
		ans = 0;
		return;
	}
	while (1) {
		int qsize = q.size();
		flag = 0;
		int emptyFlag = 0;
		for (int i = 0; i < qsize; i++) {
			info temp = q.front();
			q.pop();
			int x = temp.x;
			int y = temp.y;
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N || map[ny][nx] == WALL || map[ny][nx] == BOM) continue;
				info next;
				next.x = nx;
				next.y = ny;
				if (map[ny][nx] == EMPTY){
					countEmpty--;
				}
				flag = 1;
				map[ny][nx] = BOM;
				q.push(next);
			}
		}
		cnt++;
		if (countEmpty == 0) break;
		if (flag == 0) {
			cnt = INT_MAX;
			break;
		}
	}
	if (cnt < ans) {
		ans = cnt;
	}
}

void dfs(int depth, int s) {
	if (depth == M) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = copyMap[i][j];
			}
		}
		move();
		return;
	}
	for (int i = s; i < vcnt; i++) {

		sel.push_back(i);
		dfs(depth + 1, i + 1);
		sel.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				vloc[vcnt].y = i;
				vloc[vcnt].x = j;
				vcnt++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copyMap[i][j] = map[i][j];
		}
	}
	dfs(0, 0);
	if (ans == INT_MAX) cout << -1;
	else cout << ans;
	return 0;
}
