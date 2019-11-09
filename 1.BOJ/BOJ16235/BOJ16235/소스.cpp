#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;
deque<int> tree[11][11];
int nu[11][11];
int p[11][11];
int n, m, k; // n : 맵크기 m : 나무 갯수 , K : 시뮬 횟수
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
void simulate() {

	/* spring */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int idx = 0;
			int num_tree = tree[i][j].size();
			for (idx = 0; idx < num_tree; idx++) {
				if (nu[i][j] - tree[i][j][idx] < 0) break; // 양분 부족
				nu[i][j] -= tree[i][j][idx]; // 양분 감소시킴
				tree[i][j][idx]++; // 나무 나이 증가
			}

			/* summer */
			int s = 0;
			int idx1 = idx;
			while (idx1 < num_tree) {
				s += tree[i][j][idx1] / 2;
				idx1++;
			}
			while (idx < num_tree) {
				tree[i][j].pop_back();
				idx++;
			}
			nu[i][j] += s;
		}
	}

	/* fall */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num_tree = tree[i][j].size();
			for (int k = 0; k < num_tree; k++) {
				if (tree[i][j][k] % 5 != 0) continue;
				for (int m = 0; m < 8; m++) {
					int nx = i + dx[m];
					int ny = j + dy[m];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					tree[nx][ny].push_front(1);
				}
			}
		}
	}

	/* winter */
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			nu[i][j] += p[i][j];

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
			nu[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		x--; y--;
		tree[x][y].push_back(age);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!tree[i][j].size())
				sort(tree[i][j].begin(), tree[i][j].end(), greater<int>());
		}
	}

	while (k--) simulate();

	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans += tree[i][j].size();

	cout << ans << endl;
}