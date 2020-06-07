#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int N, L;
int map[22][22];
int ans;

void solve() {
	for (int i = 0; i < N; i++) {
		int flag = 0;
		int cnt = 1;
		for (int j = 0; j < N; j++) {
			if (j == N - 1) {
				if (map[i][j - 1] > map[i][j])
					flag = 1;
			}
			else if (map[i][j] == map[i][j + 1]) {
				cnt++;
			}
			else if (abs(map[i][j] - map[i][j + 1]) > 1) {
				flag = 1;
				break;
			}
			else if(map[i][j] > map[i][j + 1]){
				while(map[i][j] > map[i][j + 1]){////////////
					j++;
					cnt = 1;
					while (j < N - 1 && cnt != L && map[i][j] == map[i][j + 1]) {
						cnt++;
						j++;
					}
					if (cnt != L || ( j < N-1 && map[i][j] < map[i][j + 1])) {
						flag = 1;
						break;
					}
					else if(j == N-1) break;
					cnt = 1;
				}
			}
			else {
				if (cnt < L) {
					flag = 1;
					break;
				}
				cnt = 1;
			}
		}
		if (!flag) {
		//	cout << "row : " << i << endl;
			ans++;
		}
	}
	for (int j = 0; j < N; j++) {
		int flag = 0;
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			if (i == N - 1) {
				if (map[i - 1][j] > map[i][j])
					flag = 1;
			}
			else if (map[i][j] == map[i + 1][j]) {
				cnt++;
			}
			else if (abs(map[i][j] - map[i + 1][j]) > 1) {
				flag = 1;
				break;
			}
			else if (map[i][j] > map[i + 1][j]) {
				while(map[i][j] > map[i + 1][j]){////////////
					i++;
					cnt = 1;
					while (i < N - 1 && cnt != L && map[i][j] == map[i + 1][j]) {
						cnt++;
						i++;
					}
					if (cnt != L || ( i < N - 1 && map[i][j] < map[i + 1][j])) {
						flag = 1;
						break;
					}
					else if(i == N-1) break;
					cnt = 1;
				}
			}
			else {
				if (cnt < L) {
					flag = 1;
					break;
				}
				cnt = 1;
			}
		}
		if (!flag) {
			ans++;
			//cout << "col : " << j << endl;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> L;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		ans = 0;
		solve();
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}