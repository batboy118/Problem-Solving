#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int map[22][22];
int check[22][22];
struct info{
	int x;
	int y;
	int size;
	int cnt;
} s;
int totalTime;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

bool cmp(){

}

void solve(){
	queue < pair<int, int> > q;
	priority_queue < pair<int, int>, vector < pair<int, int> >, greater<pair<int, int> > > pq;
	q.push(make_pair(s.y,s.x));
	int tempTime = 0;
	while(!q.empty()){
		int flag = 1;
		int cnt = q.size();
		tempTime++;
		while(cnt--)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for(int i = 0; i < 4; i++){ //위, 왼쪽, 오른쪽, 아래
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx < 0 || nx >= N || ny < 0 || ny >= N || check[ny][nx] || map[ny][nx] > s.size) continue;
				else if (map[ny][nx] == s.size || map[ny][nx] == 0)
				{
					check[ny][nx] = 1;
					q.push(make_pair(ny,nx));
				}
				else if(map[ny][nx] < s.size){
					flag = 0;
					pq.push(make_pair(ny,nx));
				}
			}
		}
		if(flag == 0) {
			s.x = pq.top().second;
			s.y = pq.top().first;
			map[s.y][s.x] = 0;
			s.cnt++;
			if(s.cnt == s.size){
				s.size++;
				s.cnt = 0;
			}
			while(!pq.empty()) pq.pop();
			while(!q.empty()) q.pop();
			memset(check,0,sizeof(check));
			check[s.y][s.x] = 1;
			q.push(make_pair(s.y,s.x));
			totalTime += tempTime;
			tempTime = 0;
		}
	}
}

int main(){
	cin >> N;
	for(int i = 0 ; i < N ; i ++){
		for(int j = 0; j < N ; j++){
			cin >> map[i][j];
			if(map[i][j] == 9){
				map[i][j] = 0;
				s.size = 2;
				s.x = j;
				s.y = i;
			}
		}
	}
	solve();
	cout << totalTime;
	return 0;
}
