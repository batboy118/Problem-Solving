#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int N;
int map[16][16];
int dp[16][16][3];

void solve() {
    dp[0][1][0] = 1;
	for(int i = 0 ;  i < N; i++){
        for(int j = 2 ;  j < N; j++){
            if(map[i][j] == 0){
                dp[i][j][0] += dp[i][j - 1][0];
                dp[i][j][0] += dp[i][j - 1][1];
                if(i - 1 > -1)
                {   if(map[i][j - 1] == 0 && map[i - 1][j] == 0){
                        dp[i][j][1] += dp[i - 1][j - 1][0];
                        dp[i][j][1] += dp[i - 1][j - 1][1];
                        dp[i][j][1] += dp[i - 1][j - 1][2];
                    }
                    dp[i][j][2] += dp[i - 1][j][1];
                    dp[i][j][2] += dp[i - 1][j][2];
                }
            }
        }
    }
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
	solve();
	cout << dp[N-1][N-1][0] + dp[N-1][N-1][1] + dp[N-1][N-1][2];
	return 0;
}
