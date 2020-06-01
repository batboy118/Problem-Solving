#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int N, M, D;
int ans = 0;
int d;
int map[16][16];
vector < pair<int, int > > enemy;
vector< pair<int, int > > temp;

void solve(int h1, int h2, int h3) {
	int total = 0;
	int cnt = 0;
	int target[3];
	int dist[3];
	while(!temp.empty()){
		cnt++;
		for (int i = 0; i < 3; i++) {
			target[i] = -1;
			dist[i] = 9999;
		}
		for (int i = temp.size() - 1; i > -1; i--) {
			int ty = temp[i].first;
			int tx = temp[i].second;
			int td[3];
			td[0] = temp[i].first + abs(temp[i].second - h1);
			td[1] = temp[i].first + abs(temp[i].second - h2);
			td[2] = temp[i].first + abs(temp[i].second - h3);
			for (int j = 0; j < 3; j++) {
				if (td[j] <= d) {
					if (dist[j] == td[j]) {
						if (tx < temp[target[j]].second) {
							dist[j] = td[j];
							target[j] = i;
						}
					}
					else if (dist[j] > td[j]) {
						dist[j] = td[j];
						target[j] = i;
					}
				}
			}
		}
		sort(target, target + 3, greater<int>());
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				if (target[i] != -1) {
					total++;
					temp.erase(temp.begin() + target[i]);
				}
			}
			else if (target[i] != target[i - 1] && target[i] != -1) {
				total++;
				temp.erase(temp.begin() + target[i]);
			}
		}
		for (int i = temp.size() - 1; i > -1 ; i--) {
			if (temp[i].first <= cnt) {
				temp.erase(temp.begin() + i);
			}
		}
		d++;
	}
	if (ans < total) ans = total;
}

int main(){
	cin >> N >> M >> D;
	for (int i = N; i > 0; i--) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j]) enemy.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			for (int k = j + 1; k < M; k++) {
				d = D;
				temp = enemy;
				solve(i, j, k);
			}
		}
	}
	cout << ans;
	return 0;
}
