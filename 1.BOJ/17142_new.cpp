#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

#define PRINT_ARR(n, target) for(int i = 0; i < n; i++){ \
								cout << target << ' '; \
							} \
							cout <<'\n';\

#define PRINT_ARR2(n,m, target)	for(int i = 0; i < n; i++){ \
								for(int j = 0; j < m; j++){ \
									cout << target << ' '; \
								} \
								cout <<'\n';\
							}
using namespace std;



int N, M;
int map[50][50];
int copyMap[50][50];

struct VIRUS{
	int x, y;
};
int dx[] = { 0, 0, -1, 1 };
int dy[] =  {1, -1, 0, 0};

VIRUS vir[10];
int vc;

int isEdge(int y, int x) {
	return y < 0 || x < 0 || x >= N || y >= N || map[y][x] == 1;
}

int bfs(queue<VIRUS> q) {
	int ret = 0;
	int time = 0;
	while (q.size()) {
		int size = q.size();
		time++;
		while (size--) {
			VIRUS cur = q.front();
			q.pop();
			int x = cur.x;
			int y = cur.y;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (isEdge(ny, nx)) continue;
				if (map[ny][nx] == 0) {
					VIRUS temp;
					temp.x = nx;
					temp.y = ny;
					q.push(temp);
					ret = time;
					map[ny][nx] = 2;
				}
				else if (map[ny][nx] == 3) {
					VIRUS temp;
					temp.x = nx;
					temp.y = ny;
					q.push(temp);
					map[ny][nx] = 2;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) return 1234567890;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	{
		cin >> map[i][j];
		if (map[i][j] == 2) {
			vir[vc].x = j;
			vir[vc].y = i;
			vc++;
		}
		copyMap[i][j] = map[i][j];
	}
	vector<int> picker(10);
	fill(picker.begin() + vc - M, picker.begin() + vc, 1);
	int ans = 1234567890;
	do {
		//PRINT_ARR(vc, picker[i]);
		queue <VIRUS> q;
		memcpy(map, copyMap, sizeof(map));
		for (int i = 0; i < vc; i++) {
			if (picker[i]) {
				q.push(vir[i]);
			}
			else {
				map[vir[i].y][vir[i].x] = 3;
			}
		}
		int temp = bfs(q);
		if (temp < ans) ans = temp;
	} while (next_permutation(picker.begin(), picker.begin() + vc));
	if (ans == 1234567890) cout << -1;
	else cout << ans;
	return 0;
}
