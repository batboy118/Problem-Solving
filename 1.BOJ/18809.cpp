#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int N, M, R, G;
int map[52][52];
int copy_map[52][52];
int cur[51][51];
int cnt;
int ans;
int temp;
int mark[10][2];
int Gcnt;
int Rcnt;
queue<pair<int, int>> red;
queue<pair<int, int>> green;
int nx[4] = {1,0,-1,0};
int ny[4] = {0,1,0,-1};


int bfs()
{
	memset(cur, 0 , sizeof(cur));
	int cnt = 1;
	while (!green.empty() && !red.empty())
	{
		int len = green.size();
		for(int k = 0; k < len; k++) {
			int x = green.front().first;
			int y = green.front().second;
			green.pop();

			if(cur[x][y] == -1) continue; //flower

			for(int i = 0; i < 4; i++) {
					int xx = x + nx[i];
					int yy = y + ny[i];

					if(xx > N-1 || xx < 0 || yy > M-1 || yy < 0) continue;
					if(map[xx][yy] == 0) continue;
					if(map[xx][yy] == 2 || map[xx][yy] == 1) {
						green.push({xx,yy});
						map[xx][yy] = map[x][y];
						cur[xx][yy] = cnt;
					}
			}
		}

		len = red.size();
		for(int k = 0; k < len; k++) {
			int x = red.front().first;
			int y = red.front().second;
			red.pop();

			if(cur[x][y] == -1) continue; //flower

			for(int i = 0; i < 4; i++) {
					int xx = x + nx[i];
					int yy = y + ny[i];

					if(xx > N-1 || xx < 0 || yy > M-1 || yy < 0) continue;
					if(map[xx][yy] == 0) continue;


					if(map[xx][yy] == 2 || map[xx][yy] == 1) {
						red.push({xx,yy});
						map[xx][yy] = map[x][y];
						cur[xx][yy] = cnt;
					}
					else if(cur[xx][yy] == cnt && map[xx][yy] != map[x][y]) {
						map[xx][yy] = 0;
						cur[xx][yy] = -1;
						temp++;
						cout << xx <<',' << yy <<endl;
					}
			}
		}
		cnt++;
	}
}

int main()
{
	cin >> N >> M >> G >> R;
	for(int i = 0; i < N; i++)
		for(int j = 0 ; j < M; j++)
		{
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];
			if(map[i][j] == 2)
			{
				mark[cnt][0] = i;
				mark[cnt][1] = j;
				cnt++;
			}
		}
	//cnt에서 R+G만큼 뽑고 이걸 또 두개의 그룹으로 나누는데 중복을 제거하는 방법은?
	//절반 까지만 보면된다.예를들면 총 8개가 있는 경우 0~4개까지 만 그룹을 나누면 된다.
	//하지만 이 경우에도 4개 4개씩 그룹을 나누는 부분에서 중복이 발생하게 된다.
	//그런경우를 방지하는 좋은 방법은 하나를 무조건 한개의 그룹에 반드시 포함시키는 방법이다.
	for(int i = 0; i < (1 << (cnt)); i++)
	{
		Gcnt = 0;
		Rcnt = 0;;
		for(int j = 0; j < cnt; j++)
		{
			if(i & ( 1 << j ))
				Gcnt++;
			else
				Rcnt++;
			if(Gcnt > G || Rcnt > R)
				break;
		}
		if(Gcnt == G && Rcnt == R)
		{
			for(int j = 0; j < cnt; j++)
			{
				if(i & ( 1 << j )){
					green.push(make_pair(mark[j][0], mark[j][1]));
					map[mark[j][0]][mark[j][1]] = 'G';
				}
				else{
					red.push(make_pair(mark[j][0], mark[j][1]));
					map[mark[j][0]][mark[j][1]] = 'R';
				}
			}
			temp = 0;
			cout<< "----------" <<endl;
			while(!green.empty())
			{
				cout <<  green.front().first << ' ' << green.front().second << endl;
				green.pop();
			}
			cout<< endl;
			cout<< "----------" <<endl;
			while(!red.empty())
			{
				cout <<  red.front().first << ' ' << red.front().second << endl;
				red.pop();
			}
			cout<< endl;
			cout<< endl;
			//bfs();
			if(temp > ans)
				ans = temp;
			for(int i = 0; i < N; i++)
            	for(int j = 0; j < M; j++)
                	map[i][j] = copy_map[i][j];
		}
		while(!green.empty())
			green.pop();
		while(!red.empty())
			red.pop();
	}
	cout << ans;
}
//5427 불
//파이썬 itertools
//멱집합 중복되는 문제는..?
