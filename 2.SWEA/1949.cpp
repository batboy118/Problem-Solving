#include <iostream>
using namespace std;

#define Size 10

int N,K;
int map[Size][Size];
int visit[Size][Size];
int heighest;
int ans;

int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

struct info {
    int h,w;
    int height;
    bool usedk;
    int len;
};

void sol(info cur){
    ans=ans > cur.len ? ans : cur.len;

    for(int d=0; d<4;d++){
        info nxt = cur;
        nxt.h +=dir[d][0];
        nxt.w +=dir[d][1];
        nxt.height = map[nxt.h][nxt.w];

        if(nxt.h<0||nxt.h>=N || nxt.w<0||nxt.w>=N) continue;
        if(visit[nxt.h][nxt.w]) continue;

        if(nxt.height < cur.height){
            visit [nxt.h][nxt.w]=1;
            nxt.len++;
            sol(nxt);
            visit[nxt.h][nxt.w]=0;
        }
        else
        {
            if(!cur.usedk && nxt.height -K <cur.height){
                visit[nxt.h][nxt.w]=1;
                nxt.len++;
                nxt.usedk=1;
                nxt.height=cur.height-1;
                sol(nxt);
                visit[nxt.h][nxt.w]=0;
            }
        }
    }
    return;
}

int main(){

    int T;
    cin>>T;

    for(int t=1; t<=T; t++){
        cin>>N>>K;
        heighest = ans =0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N;j++){
                cin>>map[i][j];
                if (heighest <= map[i][j]){
                    heighest=map[i][j];
                }
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N;j++){
                if(heighest ==map[i][j]){
                    visit[i][j]=1;
                    info cur = {i, j, map[i][j], 0, 1};
                    sol(cur);
                    visit[i][j]=0;
                }
            }
        }
        cout<<'#'<<t<<' '<<ans<<'\n';
    }
    return 0;
}

