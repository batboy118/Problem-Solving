#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, M;
int map[52][52];
int order[15];
int chcnt;
int homecnt;
pair <int, int> home[105];
pair <int, int> ch[15];

int solve() {
	int total = 0;
	for (int i = 0; i < homecnt; i++) {
		int temp;
		int min = INT_MAX;
		for (int j = 0; j < chcnt; j++) {
			if (order[j]) {
				temp = abs(home[i].first - ch[j].first) + abs(home[i].second - ch[j].second);
				if (min > temp) min = temp;
			}
		}
		total += min;
	}
	return total;
}

int main() {
	cin >> N >> M;
	int a;
	int ans = INT_MAX;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
			if (map[i][j] == 1) {
				home[homecnt] = make_pair(i,j);
				homecnt++;
			}
			else if (map[i][j] == 2) {
				ch[chcnt] = make_pair(i, j);
				chcnt++;
			}
		}
	}
	memset(order, 0, sizeof(order));
	for (int i = chcnt - M; i < chcnt; i++) {
		order[i] = 1;
	}
	do {
		int temp = solve();
		if (temp < ans)	ans = temp;
	} while (next_permutation(order, order+ chcnt));
	cout << ans;
	return 0;
}
