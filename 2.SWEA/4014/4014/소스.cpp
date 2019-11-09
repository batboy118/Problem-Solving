#include<iostream>
#define MAX 21
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int N, X, T;
int map[MAX][MAX];
int result;
int cnt;

void SearchRight(int k, int dir) {
	for (int idx = 0; idx < N; idx++) {

		

		if (map[k][idx] <= map[k][idx + X] - 2 || map[k][idx] >= map[k][idx + X] + 2) { break; }
		else if (map[k][idx] == map[k][idx + X]) {
			continue;
		}
		else if (map[k][idx] < map[k][idx + X]) {
			cnt = 1;
			while (map[k][idx] != map[k][idx+1]) {
				cnt++;
				idx++;				
			}
			if (cnt < X) break;
			
		}
		else if (map[k][idx] > map[k][idx + X]) {
			bool flag = true;
			for (int i = 1; i < X+1; i++) {
				if (map[k][idx] < map[k][idx + i]) {
					flag = false;
					break;
				}
				else if (map[k][idx] > map[k][idx + i]) {
					idx = idx + i;
					break;
				}
			}
			if (!flag) break;
			else {
				for (int i = 0; i < X; i++) {
					if (map[k][idx] != map[k][idx + i]) {
						flag = false;
						break;
					}
				}
			if (!flag) break;
			idx = idx + X - 1;
			}
		}
		

		if (idx > N - 1) { break; }

		if (idx + X > N - 1) {
			for (int i = 0; N - 1 >= idx + i; i++) {
				if (map[k][idx] != map[k][idx + i])return;
			}
			result += 1;

			return;
		}
	}
}

void SearchDown(int k, int dir) {
	for (int idx = 0; idx < N; idx++) {

		

		if (map[idx][k] <= map[idx + X][k] - 2 || map[idx][k] >= map[idx + X][k] + 2) { break; }
		else if (map[idx][k] == map[idx + X][k]) {
			continue;
		}
		else if (map[idx][k] < map[idx + X][k]) {
			cnt = 1;
			while (map[idx][k] != map[idx + 1][k]) {
				cnt++;
				idx++;
			}
			if (cnt < X) break;

		}
		else if (map[idx][k] > map[idx + X][k]) {
			bool flag = true;
			for (int i = 1; i < X+1; i++) {
				if (map[idx][k] < map[idx + i][k]) {
					flag = false;
					break;
				}
				else if (map[idx][k] > map[idx + i][k]) {
					idx = idx + i;
					break;
				}
			}
			if (!flag) break;
			else {
				for (int i = 0; i < X; i++) {
					if (map[idx][k] != map[idx + i][k]) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
				idx = idx + X - 1;
			}
		}


		if (idx > N - 1) { break; }
		if (idx + X > N - 1) {
			for (int i = 0; N - 1 >= idx + i; i++) {
				if (map[idx][k] != map[idx + i][k])return;
			}
			result += 1;

			return;
		}
	}
}

void solve() {

	//가로 탐색
	for (int i = 0; i < N; i++) {
		SearchRight(i , RIGHT);
	}

	//세로 탐색
	for (int j = 0; j < N; j++) {
		SearchDown(j, DOWN);
	}
}


int main(int argc, char** argv)
{
	int test_case;
	

	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> X;
		
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				map[i][j]=0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		result = 0;
		solve();

		cout << '#' << test_case << ' ' << result << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}