#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>

//선택하는방법 3가지
//시물레이션 DFS, BFS 2가지
// 총 6가지 조함으로 풀었음

using namespace std;

int N, M;
int map[9][9];
int co[9][9];
int ans = INT_MIN;
int temp;
int x1, x2, x3;
int y_1;
int y_2;
int y_3;
vector < pair<int, int> > virus;
vector < pair<int, int> > space;
vector <pair <int, int> > walls;
queue <pair <int, int> > q;

int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

void dfs(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nx = c + dx[i];
		int ny = r + dy[i];
		if (nx > -1 && nx < M && ny > -1 && ny < N && map[ny][nx] == 0) {
			map[ny][nx] = 2;
			temp++;
			dfs(ny, nx);
		}
	}
}

void bfs() {
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
		while (!q.empty()) {
			int len = q.size();
			while (len--) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];
					if (nx > -1 && nx < M && ny > -1 && ny < N && map[ny][nx] == 0) {
						map[ny][nx] = 2;
						temp++;
						q.push(make_pair(ny, nx));
					}
				}
			}
		}
	}
}

void select_for() {
	//for (int i = 0; i < M * N - 2; i++) {
	//	x1 = i % M;
	//	y_1 = i / M;
	//	if (map[y_1][x1]) continue;
	//	for (int j = i + 1; j < M * N - 1; j++) {
	//		x2 = j % M;
	//		y_2 = j / M;
	//		if (map[y_2][x2]) continue;
	//		for (int k = j + 1; k < M * N; k++) {
	//			x3 = k % M;
	//			y_3 = k / M;
	//			if (map[y_3][x3]) continue;
	//			map[y_1][x1] = 1;
	//			map[y_2][x2] = 1;
	//			map[y_3][x3] = 1;
	//			temp = 0;
	//			for (int v = 0; v < virus.size(); v++) {
	//				dfs(virus[v].first, virus[v].second);
	//			}
	//			if (ans < (int)space.size() - temp - 3) {
	//				ans = space.size() - temp - 3;
	//			}
	//			memcpy(map, co, sizeof(co));
	//		}
	//	}
	//}
	for (int i = 0; i < space.size() - 2; i++) {
		for (int j = i + 1; j < space.size() - 1; j++) {
			for (int k = j + 1; k < space.size(); k++) {
				map[space[i].first][space[i].second] = 1;
				map[space[j].first][space[j].second] = 1;
				map[space[k].first][space[k].second] = 1;
				temp = 0;
				// 1번 DFS
				//for (int v = 0; v < virus.size(); v++) {
				//	dfs(virus[v].first, virus[v].second);
				//}

				// 2번 BFS
				bfs();
				if (ans < (int)space.size() - temp - 3) {
					ans = space.size() - temp - 3;
				}
				memcpy(map, co, sizeof(co));
			}
		}
	}
}

void select_rec(int depth, int k) {
	if (depth == 3) {
		for (int i = 0; i < 3 ; i++) {
			map[walls[i].first][walls[i].second] = 1;
		}
		temp = 0;
		// 1번 DFS
		//for (int v = 0; v < virus.size(); v++) {
		//	dfs(virus[v].first, virus[v].second);
		//}

		// 2번 BFS
		bfs();

		if (ans < (int)space.size() - temp - 3) {
			ans = space.size() - temp - 3;
		}
		memcpy(map, co, sizeof(co));
		return;
	}
	for (size_t i = k; i < space.size(); i++) {
		walls.push_back(space[i]);
		select_rec(depth + 1, i + 1);
		walls.pop_back();
	}
}

void select_next_permutation() {
	int order[81];
	fill(order, order + space.size() - 3, 0);
	fill(order + space.size() - 3, order + space.size(), 1);
	do {
		for (int i = 0; i < space.size(); i++) {
			if (order[i]) {
				map[space[i].first][space[i].second] = 1;
			}
		}
		temp = 0;
		// 1번 DFS
		//for (int v = 0; v < virus.size(); v++) {
		//	dfs(virus[v].first, virus[v].second);
		//}

		// 2번 BFS
		bfs();

		if (ans < (int)space.size() - temp - 3) {
			ans = space.size() - temp - 3;
		}
		memcpy(map, co, sizeof(co));
	} while (next_permutation(order, order + space.size()));
}

int main() {
	cin >> N >> M;
	for (size_t i = 0; i < N; i++){
		for (size_t j= 0;  j < M;  j++)	{
			cin >> co[i][j];
			if (co[i][j] == 2) virus.push_back(make_pair(i, j));
			else if (co[i][j] == 0) space.push_back(make_pair(i, j));
		}
	}
	memcpy(map, co, sizeof(co));
	//select_for();             //1번
	//select_rec(0, 0);       //2번
	select_next_permutation(); //3번
	cout << ans;
	return 0;
}
