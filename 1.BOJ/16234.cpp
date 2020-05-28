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
vector <pair<int,int> > adj[52][52];
int ans;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 ,0 };

int openGate(){
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = (i + 1) % 2; j < N; j += 2){
			for (int d = 0; d < 4; d++) {
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				int gap = abs(a[i][j] - a[ny][nx]);
				if (gap >= L && gap <= R) {
					adj[i][j].push_back(make_pair(ny,nx));
					adj[ny][nx].push_back(make_pair(i, j));
					cnt++;
				}
			}
		}
	}
	return cnt;
}

void move(){
	memset(check, 0, sizeof(check));
	for (int i = 0; i < N; i++) {
		for (int j = (i + 1) % 2; j < N; j += 2) {
			if (check[i][j]) continue;
			int cnt = 1;
			int total = a[i][j];
			queue < pair <int, int> > q;
			queue < pair <int, int> > temp;
			q.push(make_pair(i, j));
			temp.push(make_pair(i, j));
			check[i][j] = 1;
			while (!q.empty()) {
				int len = q.size();
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				while(len--){
					for (vector<pair <int,int> >:: iterator iter = adj[y][x].begin(); iter != adj[y][x].end(); iter++){
						if (check[iter->first][iter->second]) continue;
						q.push(*iter);
						temp.push(*iter);
						check[iter->first][iter->second] = 1;
						total += a[iter->first][iter->second];
						cnt++;
					}
					adj[y][x].clear();
				}
			}
			int setVal = total / cnt;
			while (!temp.empty()) {
				int y = temp.front().first;
				int x = temp.front().second;
				a[y][x] = setVal;
				temp.pop();
			}
		}
	}
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> a[i][j];
		}
	}
	while (openGate()) {
		move();
		ans++;
	}
	cout << ans;
	return 0;
}
