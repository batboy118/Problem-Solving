#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;

int map[105][105];
int x, y, d, g;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
struct info {
	int y, x, dir;
};
vector <info> v;

void solve() {
	info temp;
	map[y][x] = 1;
	temp.y = y + dy[d];
	temp.x = x + dx[d];
	temp.dir = d;
	v.push_back(temp);
	y = temp.y ;
	x = temp.x ;
	while (g--) {
		int len = v.size();
		for (int i = len - 1; i > -1; i--) {
			info next;
			next.dir = (v[i].dir + 1) % 4;
			next.y = y + dy[next.dir];
			next.x = x + dx[next.dir];
			v.push_back(next);
			y = next.y;
			x = next.x;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		map[v[i].y][v[i].x] = 1;
	}
	v.clear();
}

int count_rect() {
	int cnt = 0;
	for(int i  = 0 ; i < 100; i++)
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				cnt++;
		}
	return cnt;
}

int main() {
	int cnt;
	cin >> cnt;
	while (cnt--) {
		cin >> x >> y >> d >> g;
		solve();
	}
	cout << count_rect();
	return 0;
}
