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

int N, M;
int p[22][22];
int x, y, k;
int dir;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int dice[7];

void changeDir(int d) {
    if (d == 0)
    {
        int temp = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = temp;
    }
    else if (d == 1)
    {
        int temp = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = dice[1];
        dice[1] = temp;
    }
    else if (d == 2)
    {
        int temp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = temp;
    }
    else if (d == 3)
    {
        int temp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = temp;
    }
}

int main() {
	cin >> N >> M >> y >> x >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> p[i][j];
		}
	}
	while (k--) {
		cin >> dir;
		dir--;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= M || ny >= N || ny < 0) continue;
		changeDir(dir);
        if (p[ny][nx] == 0) p[ny][nx] = dice[6];
        else {
            dice[6] = p[ny][nx];
            p[ny][nx] = 0;
        }
        y = ny;
        x = nx;
        cout << dice[1] << "\n";
	}
	return 0;
}
