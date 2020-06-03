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

int N;
int m[20][20][2];
int cp[20][20];
int dir[5];
int ans;

deque < pair<int,int> > snake;
vector < pair<int, char> > moves;

void moveUP() {
	for (int j = 0; j < N; j++) {
		for (int i = 1; i < N; i++) {
			if (m[i][j][0] == 0) continue;
			int cnt = 1;
			while (i - cnt > -1 && m[i - cnt][j][0] == 0) cnt++;
			if (i-cnt > -1 && m[i - cnt][j][0] == m[i][j][0] && m[i - cnt][j][1] == 0) {
				m[i - cnt][j][1] = 1;
				m[i - cnt][j][0] *= 2;
				m[i][j][0] = 0;
			}
			else {
				int temp = m[i][j][0];
				m[i][j][0] = 0;
				m[i - cnt + 1][j][0] = temp;
			}
		}
	}
}

void moveDOWN() {
	for (int j = 0; j < N; j++) {
		for (int i = N - 2; i > -1; i--) {
			if (m[i][j][0] == 0) continue;
			int cnt = 1;
			while (i + cnt < N && m[i + cnt][j][0] == 0) cnt++;
			if (i + cnt < N && m[i + cnt][j][0] == m[i][j][0] && m[i + cnt][j][1] == 0) {
				m[i + cnt][j][1] = 1;
				m[i + cnt][j][0] *= 2;
				m[i][j][0] = 0;
			}
			else {
				int temp = m[i][j][0];
				m[i][j][0] = 0;
				m[i + cnt - 1][j][0] =temp;
			}
		}
	}
}

void moveLEFT() {
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (m[i][j][0] == 0) continue;
			int cnt = 1;
			while (j - cnt > -1 && m[i][j - cnt][0] == 0) cnt++;
			if (j - cnt > -1 && m[i][j - cnt][0] == m[i][j][0] && m[i][j - cnt][1] == 0) {
				m[i][j - cnt][1] = 1;
				m[i][j - cnt][0] *= 2;
				m[i][j][0] = 0;
			}
			else {
				int temp = m[i][j][0];
				m[i][j][0] = 0;
				m[i][j - cnt + 1][0] = temp;
			}
		}
	}
}

void moveRIGHT() {
	for (int i = 0; i < N; i++) {
		for (int j = N - 2; j > -1; j--) {
			if (m[i][j][0] == 0) continue;
			int cnt = 1;
			while (j + cnt < N && m[i][j + cnt][0] == 0) cnt++;
			if (j + cnt < N && m[i][j + cnt][0] == m[i][j][0] && m[i][j + cnt][1] == 0) {
				m[i][j + cnt][1] = 1;
				m[i][j + cnt][0] *= 2;
				m[i][j][0] = 0;
			}
			else {
				int temp = m[i][j][0];
				m[i][j][0] = 0;
				m[i][j + cnt - 1][0] = temp;

			}
		}
	}
}

void move() {
	for (size_t i = 0; i < 5; i++) {
		if (dir[i] == 0) {
			moveUP();
		}
		else if (dir[i] == 1) {
			moveDOWN();
		}
		else if (dir[i] == 2) {
			moveLEFT();
		}
		else{
			moveRIGHT();
		}
		for (size_t j = 0; j < N; j++) {
			for (size_t k = 0; k < N; k++) {
				m[j][k][1] = 0;
			}
		}
	}
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			if (ans < m[i][j][0]) {
				ans = m[i][j][0];
			}
		}
	}
}

void select_dir(int depth) {
	if (depth == 5) {
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < N; j++) {
				m[i][j][0] = cp[i][j];
			}
		}
		move();
		return;
	}
	for (size_t i = 0; i < 4; i++) {
		dir[depth] = i;
		select_dir(depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N ;
	for (size_t i = 0; i < N; i++){
		for(size_t j = 0; j < N; j++){
			cin >> cp[i][j];
		}
	}
	select_dir(0);
	cout << ans;
	return 0;
}
