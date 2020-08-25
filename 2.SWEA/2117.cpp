#include<iostream>
#include<cmath>
#define MAX 20
using namespace std;

struct Info{
	int x, y;
};

Info House[400];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int T;
int N, M;
int K;
int Cost;
int result;
int cnt;
int temp;
int numOfHouse;

void cal(int x, int y) {
	for (int i = 0; i < numOfHouse; i++) {
		if (abs(x - House[i].x) + abs(y - House[i].y) < K) {
			cnt++;
		}
	}
}

void solve() {
	for (K = 1; K <= N + 1; K++) {
		Cost = (K*K) + (K - 1)*(K - 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cnt = 0;
				cal(j,i);
				if (Cost <= cnt*M && cnt > result) { result = cnt; }
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
		numOfHouse = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> temp;
				if (temp == 1) {
					House[numOfHouse].x = j;
					House[numOfHouse].y = i;
					numOfHouse++;
				}
			}
		}
		result = 0;
		solve();
		cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;
}
