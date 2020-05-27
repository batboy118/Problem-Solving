#include <iostream>
#include <limits.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

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

struct info{
    int node[2];
    int cost;
};

vector <info> sortedList;
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

int parent[7];

void make_set(){
    for(int i = 1; i <=cnt; i++){
        parent[i] = i;
    }
}

void union_set(int a, int b){
    if(parent[a] > parent[b]){
        int temp = parent[a];
        for(int i = 1; i <= cnt; i++){
            if(parent[i] == temp)
                parent[i] = parent[b];
        }
    }
    else{
        int temp = parent[b];
        for(int i = 1; i <= cnt; i++){
            if(parent[i] == temp)
                parent[i] = parent[a];
        }
    }
}

void mst(){
    make_set();
    for(int i = 0; i < sortedList.size() ;i++){
        if(parent[sortedList[i].node[0]] != parent[sortedList[i].node[1]]){
            union_set(sortedList[i].node[0], sortedList[i].node[1]);
            ans += sortedList[i].cost;
        }
    }
    for(int i = 1; i < cnt; i++){
        if(parent[i] != parent[i+1]){
            ans = -1;
            return;
        }
    }
}

bool cmp(const info &a, const info &b){
    return a.cost < b.cost;
}

void get_sorted_list(){
    for(int i = 2; i <= cnt; i++){
        for(int j = 1; j < i; j++){
            if(Icheck[i][j]){
                info temp;
                temp.node[0] = i;
                temp.node[1] = j;
                temp.cost = Icheck[i][j];
                sortedList.push_back(temp);
            }
        }
    }
    sort(sortedList.begin(), sortedList.end(), cmp);
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
    ans = 0;
    get_sorted_list();
    mst();
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

    cout << ans;
    return 0;
}
