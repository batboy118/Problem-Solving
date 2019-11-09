#include<iostream>

#define endl '\n'

using namespace std;

#define UR 0
#define DR 1
#define DL 2
#define UL 3

int dx[4] = { 1,1,-1,-1 };
int dy[4] = { -1,1,1,-1 };

int N;
int map[20][20];
int check[101];
int result;
int temp;

bool isWall(int x, int y) {
	if (x<0 || x>N - 1 || y < 0 || y > N - 1) return true;
	else return false;
}

bool search(int y, int x, int dir1, int dir2) {

	int nx = x;
	int ny = y;
	check[map[ny][nx]] = true;
	temp++;

	for (int i = 0; i < dir1; i++) {
		nx += dx[UR];
		ny += dy[UR];
		//	cout << nx << ' ' << ny << endl;
		if (isWall(nx, ny)) { return false; }
		if (check[map[ny][nx]]) { return false; }
		check[map[ny][nx]] = true;
		temp++;
	}

	for (int i = 0; i < dir2; i++) {
		nx += dx[DR];
		ny += dy[DR];
		//	cout << nx << ' ' << ny << endl;
		if (isWall(nx, ny)) { return false; }
		if (check[map[ny][nx]]) { return false; }
		check[map[ny][nx]] = true;
		temp++;
	}
	for (int i = 0; i < dir1; i++) {
		nx += dx[DL];
		ny += dy[DL];
		//	cout << nx << ' ' << ny << endl;
		if (isWall(nx, ny)) { return false; }
		if (check[map[ny][nx]]) { return false; }
		check[map[ny][nx]] = true;
		temp++;
	}
	for (int i = 0; i < dir2 - 1; i++) {
		nx += dx[UL];
		ny += dy[UL];
		//	cout << nx << ' ' << ny << endl;
		if (isWall(nx, ny)) { return false; }
		if (check[map[ny][nx]]) { return false; }
		check[map[ny][nx]] = true;
		temp++;
	}

	return true;
}

void initCheck() {
	for (int i = 0; i <= 100; i++) {
		check[i] = false;
	}
}

void solve() {

	result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int dir1 = N - 2; dir1 >= 1; dir1--) {
				for (int dir2 = N - 2; dir2 >= 1; dir2--) {
					if (result > 2 * (dir1 + dir2)) continue;
					initCheck();
					if (search(i, j, dir1, dir2)) {
						if (temp > result) result = temp;
					}
					temp = 0;
				}
			}
		}
	}
	if (result == 0) result = -1;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}



		solve();

		cout << '#' << test_case << ' ' << result << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}