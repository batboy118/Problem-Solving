#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

int ans;
int N,M,R,C,L;
int map[50][50];
int visit[50][50];
int dy[8][4]{
    {0,0,0,0},
    {0, 0, 1, -1},   //동, 서, 남, 북
    {0, 0, 1, -1},   
    {0, 0, 0, 0},
    {0, 0, 0, -1},
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, -1}
};
int dx[8][4]{
     {0,0,0,0},
    {1, -1, 0, 0},
    {0, 0, 0, 0},
    {1, -1, 0, 0},
    {1, 0, 0 , 0},
    {1, 0, 0, 0},
    {0, -1, 0, 0},
    {0, -1, 0, 0}
};
int availNext[8][4] = {
    {0,0,0,0},
    {1,1,1,1},
    {0,0,1,1},
    {1,1,0,0},
    {0,1,1,0},
    {0,1,0,1},
    {1,0,0,1},
    {1,0,1,0}
};

void solve(){
    queue <pair<int,int> > q;
    q.push(make_pair(R,C));
    visit[R][C] = 1;
    ans++;
    while(--L){
        int len = q.size();
        while(len--){
            int y = q.front().first;
            int x = q.front().second;
            int val = map[y][x];
            q.pop();
            for(int i = 0; i < 4; i++){
                int ny = y + dy[val][i];
                int nx = x + dx[val][i];
                if (ny < 0 || nx < 0 || nx >= M || ny >= N || visit[ny][nx] || map[ny][nx] == 0) continue;
                if (availNext[map[ny][nx]][i]){
                    visit[ny][nx] = 1;
                    ans++;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> M >> R >> C >> L;
        for(int i = 0 ; i < N; i ++){
            for (int j = 0; j < M; j++){
                cin >> map[i][j];
            }
        }
        ans = 0;
        memset(visit, 0, sizeof(visit));
        solve();
        cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}