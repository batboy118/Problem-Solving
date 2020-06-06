#include<iostream>
#include<string.h>

using namespace std;

int N, M, C;
int map[10][10];
int a[5];
int b[5];
int maxA = 0;
int maxB = 0;
int tempMax = 0;

void get_Max(int depth, int arr[], int val, int cnt) {
	if (cnt > C) return ;
	if (depth >= M) {
		if (val > tempMax) tempMax = val;
		return ;
	}
	get_Max(depth + 1, arr, val + a[depth] * a[depth], cnt + a[depth]);
	get_Max(depth + 1, arr, val, cnt);
	return ;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ans = 0;
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - M + 1; j++) {
				for (int k = 0; k < M; k++) {
					a[k] = map[i][j + k];
					tempMax = 0;
					get_Max(0, a, 0, 0);
					maxA = tempMax;
				}
				for (int ii = i; ii < N; ii++) {
					for (int jj = 0; jj < N - M + 1; jj++) {
						if (i * N + j + M > ii * N + jj) continue;
						for (int k = 0; k < M; k++) {
							a[k] = map[ii][jj + k];
						}
						tempMax = 0;
						get_Max(0, b, 0, 0);
						maxB = tempMax;
						if (ans < maxA + maxB)
							ans = maxA + maxB;
					}
				}
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
