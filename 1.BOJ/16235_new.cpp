#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <string.h>

using namespace std;

struct info {
	int y;
	int x;
	int age;
};

int N, M, K;
int energy[12][12];
vector<info> tree;
vector<info> dead;
vector<info> five;
vector<info> alive;
int a[12][12];

int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[8] = { 0, 1, -1, 1, -1, 0, 1, -1 };

void spring() {
	while (!tree.empty()) {
		info t = tree.back();
		tree.pop_back();
		if (t.age <= energy[t.y][t.x]) {
			energy[t.y][t.x] -= t.age;
			t.age++;
			if (t.age % 5 == 0) {
				info tt = t;
				five.push_back(tt);
			}
			alive.push_back(t);
		}
		else {
			dead.push_back(t);
		}
	}
	while (!alive.empty()) {
		info t = alive.back();
		tree.push_back(t);
		alive.pop_back();
	}
}

void summer() {
	while (!dead.empty()) {
		info t = dead.back();
		dead.pop_back();
		energy[t.y][t.x] += t.age / 2;
	}
}

void fall() {
	while(!five.empty()){
		info t = five.back();
		five.pop_back();
		for (int i = 0; i < 8; i++) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;
			info temp;
			temp.y = ny;
			temp.x = nx;
			temp.age = 1;
			tree.push_back(temp);
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			energy[i][j] += a[i][j];
		}
	}
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			energy[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		info t;
		cin >> t.y >> t.x >> t.age;
		t.y--;
		t.x--;
		tree.push_back(t);
	}
	while (K--) {
		spring();
		summer();
		fall();
		winter();
	}
	cout << tree.size();
	return 0;
}
