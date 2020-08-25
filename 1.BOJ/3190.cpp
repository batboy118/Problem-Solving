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

int N, K, L;
int m[100][100];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int dir;
int t;
deque < pair<int,int> > snake;
vector < pair<int, char> > moves;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		m[--y][--x] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int X;
		char d;
		cin >> X;
		cin >> d;
		moves.push_back(make_pair(X, d));
	}
	moves.push_back(make_pair(200, 0));
	snake.push_back(make_pair(0, 0));
	m[0][0] = -1;

	for (int i = 0; i < L + 1; i++) {
		int flag = 0;
		while (t < moves[i].first) {
			t++;
			int ny = snake.front().first + dy[dir];
			int nx = snake.front().second + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || m[ny][nx] == -1) {
				flag = 1;
				break;
			}
			else if(m[ny][nx] == 1){
				snake.push_front(make_pair(ny, nx));
				m[ny][nx] = -1;
			}
			else {
				snake.push_front(make_pair(ny, nx));
				m[ny][nx] = -1;
				m[snake.back().first][snake.back().second] = 0;
				snake.pop_back();
			}
		}
		if (flag) break;
		if (moves[i].second == 'L') {
			dir = (dir + 3) % 4;
		}
		else {
			dir = (dir + 1) % 4;
		}
	}
	cout << t;
	return 0;
}
