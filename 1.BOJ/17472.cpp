#include <iostream>
#include <limits.h>
#include <string.h>

using namespace std;
int N,M;
int o[12][12];
int ans = -1;
int cnt;
int check[12][12];
int copyMap[12][12];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int Icheck[7][7];
int visit[7][7];
void updateMap(int i, int j){
    check[i][j] = 1;
    copyMap[i][j] = cnt;
    for(int d = 0; d < 4; d++){
        int nx = j + dx[d];
        int ny = i + dy[d];
        if(nx < 0 || ny < 0 || ny >= N || nx >= M ||
            check[ny][nx] || o[ny][nx] == 0) continue;
        updateMap(ny, nx);
    }
}
void countIsland(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(o[i][j] == 1 && check[i][j] == 0){
                cnt++;
                updateMap(i, j);
            }
        }
    }
}
void buildBridge(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
              o[i][j] = copyMap[i][j];
        }
    }
    for(int i = 1; i <= cnt; i++){
        for(int j = 1; j <= cnt; j++){
              Icheck[i][j] = 0;
        }
    }
    int start;
    int end;
    int temp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            temp = 0;
            if(o[i][j] == 0) continue;
            start = o[i][j];
            while(j < M && o[i][++j] == start){};
            while(j < M && o[i][j] == 0){
                j++;
                temp++;
            }
            if(j < M){
                end = o[i][j];
                if(temp > 1){
                    if(Icheck[start][end] == 0 || Icheck[start][end] > temp){
                        Icheck[start][end] = temp;
                        Icheck[end][start] = temp;
                    }
                }
                j--;
            }
        }
    }
    for(int j = 0; j < M; j++){
        for(int i = 0; i < N; i++){
            temp = 0;
            if(o[i][j] == 0) continue;
            start = o[i][j];
            while(i < N && o[++i][j] == start){};
            while(i < N && o[i][j] == 0){
                i++;
                temp++;
            }
            if(i < N){
                end = o[i][j];
                if(temp > 1){
                    if(Icheck[start][end] == 0 || Icheck[start][end] > temp){
                        Icheck[start][end] = temp;
                        Icheck[end][start] = temp;
                    }
                }
                i--;
            }
        }
    }
}

int cc[7];
void dfs(int depth){
    if(depth == cnt){
		memset(cc, 0, sizeof(cc));
        int temp = 0;
        for(int i = 1; i <= cnt; i ++){
            for(int j = 1; j <= cnt; j ++){
                if(visit[i][j]){
					cc[i] = 1;
					cc[j] = 1;
                    temp += Icheck[i][j];
				}
            }
        }
		for(int i = 1; i <= cnt; i++){
			if(cc[i] == 0) return;
		}
        if(temp < ans)
            ans = temp;
		if(temp == 10){
			for(int i = 1; i <= cnt; i ++){
            	for(int j = 1; j <= cnt; j ++){
                	if(visit[i][j]){
						cout << i << " = > " << j << endl;
					}
				}
			}
			cout << endl;
		}
    }
    for(int i = 1; i <= cnt; i++){
        if(Icheck[depth][i] && visit[i][depth] == 0){
            visit[depth][i] = 1;
            dfs(depth + 1);
            visit[depth][i] = 0;
        }
    }
}
void getAns(){
    for(int i = 1; i <= cnt; i++){
        int flag = 1;
        for(int j = 1; j <= cnt; j++){
              if(Icheck[i][j]){
                  flag = 0;
              }
        }
        if(flag) return;
    }
    ans = INT_MAX;
    dfs(1);
    if(ans == INT_MAX)
        ans = -1;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
              cin >> o[i][j];
        }
    }
    countIsland();
    buildBridge();
    getAns();

    cout << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
              cout << o[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 1; i <= cnt; i++){
        for(int j = 1; j <= cnt; j++){
              cout << Icheck[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << ans;
    return 0;
}
