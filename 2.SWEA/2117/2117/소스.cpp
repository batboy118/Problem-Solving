#include<iostream>


#define DEB
#define MAX 20
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int T;
int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];
int K;
int Cost;
int result;
int cnt;

void dfs(int depth, int x, int y) {
	
	
	if (map[y][x]) cnt++;
	visited[y][x] = true;
	depth++;

	 if (depth <= K) {
		 
		 for (int i = 0; i < 4; i++) {

			 int nx = x + dx[i];
			 int ny = y + dy[i];

			 if (nx >= 0 && nx < N && ny >= 0 && ny < N)

				 if (visited[ny][nx] == false) {
					 
					 dfs(depth, nx, ny);
				 }
		 }
	 }

}

void solve() {
	for (K = 1; K <= N + 1; K++) {
		Cost = (K*K) + (K - 1)*(K - 1);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cnt = 0;
				dfs(1, j, i);
				if (Cost <= cnt*M && cnt > result) { result = cnt; }
#ifdef DEB
				cout << K << "ÀÇ" << j << ',' << i << "  ¹øÂ° visited  " << endl;
				for (int y = 0; y < N; y++) {
					for (int x = 0; x < N; x++) {
						cout << visited[y][x] << ' ';
					}
					cout << endl;
				}

				cout << endl;
#endif


				for (int y = 0; y < N; y++) {
					for (int x = 0; x < N; x++) {
						visited[y][x] = false;
					}
				}
			}
		}


	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				visited[i][j] = false;
			}
		}

		result = 0;

		solve();


		cout << '#' << test_case << ' ' << result << '\n';

	}

	return 0;
}