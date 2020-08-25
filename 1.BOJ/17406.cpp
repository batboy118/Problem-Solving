#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int A[52][52];
int cp[52][52];
int ans = (1 << 31) - 1;
struct info {
	info(int r, int c, int s) : x1(c-s), x2(c+s), y1(r-s), y2(r+s)  {}
	int x1, x2, y1, y2;
};
queue <info> q;
vector <info> v;

void move() {
	while (!q.empty()) {
		info temp = q.front();
		q.pop();
		int x1 = temp.x1,  x2 = temp.x2,  y1 = temp.y1,  y2 = temp.y2;
		while (x1 < x2) {
			int temp = A[y1][x1];
			for (int i = y1; i < y2; i++) {
				A[i][x1] = A[i + 1][x1];
			}
			for (int i = x1; i < x2; i++) {
				A[y2][i] = A[y2][i + 1];
			}
			for (int i = y2; i > y1; i--) {
				A[i][x2] = A[i - 1][x2];
			}
			for (int i = x2; i > x1 + 1; i--) {
				A[y1][i] = A[y1][i - 1];
			}
			A[y1][x1 + 1] = temp;
			x1++, x2--, y1++, y2--;
		}
	}
}

void get_min_row(){
	int temp;
	for (int i = 1; i <= N; i++) {
		temp = 0;
		for (int j = 1; j <= M; j++) {
			temp += A[i][j];
		}
		if (ans > temp) ans = temp;
	}
}

int main() {
	cin >> N >> M >> K;
	int order[6] = { 0, 1,2,3,4,5 };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> cp[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		info temp(r,c,s);
		v.push_back(temp);
	}
	do {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				A[i][j] = cp[i][j];
			}
		}
		for (int i = 0; i < K; i++) {
			q.push(v[order[i]]);
		}
		move();
		get_min_row();
	} while (next_permutation(order, order + K));
	cout << ans;
	return 0;
}
