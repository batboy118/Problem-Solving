#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

int N, K;
int map[20][20];
int visit[20][20];
struct info {
	int x, y, xx, yy;
};
vector <info> c;
int tx, ty, fuel;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void solve() {
	int flag = 0;
	int dist = 0;
	int selected = 0;

	while (K--) {
		queue <pair<int, int> > q;
		vector <pair<int, int> > v;

		//초기 상태
		memset(visit, 0, sizeof(visit));
		while (!q.empty()) q.pop();
		q.push({ ty,tx });
		visit[ty][tx] = 1;
		flag = 0;
		dist = 0;
		selected = 0;


		//가까운 승객 찾기
		while (1) {
			dist++;
			int len = q.size();
			while (len--) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for(int i = 0; i < 4; i++){
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[ny][nx] || map[ny][nx] == 1) continue;
					if (map[ny][nx] > 9) {
						flag = 1;
						v.push_back({ ny,nx });
					}
					q.push({ ny,nx });
					visit[ny][nx] = 1;
				}
			}
			//flag1 이면 승객 발견한 것
			if (flag == 1) {

				//승객위치까지의 사용된 연료 제거
				fuel -= dist;

				while (!q.empty()) q.pop(); // 큐 비우기

				int minY = 999;
				int minX = 999;

				//같은 거리에 있는 승객중 가장 위, 가장 왼쪽 승객 선택
				for (int i = 0; i < v.size(); i++) {
					if (minY > v[i].first) {
						minY = v[i].first;
						minX = v[i].second;
						selected = map[v[i].first][v[i].second] - 10;
					}
					else if (minY == v[i].first) {
						if (minX > v[i].second) {
							minX = v[i].second;
							selected = map[v[i].first][v[i].second] - 10;
						}
					}
				}
				//승객 맵에서 삭제
				map[c[selected].y][c[selected].x] = 0;
				break;
			}
		}

		if (fuel <= 0) return;

		//택시 위치 갱신
		ty = c[selected].y;
		tx = c[selected].x;

		//목적지 -1로 설정
		int destX = c[selected].xx;
		int destY = c[selected].yy;
		map[destY][destX] = -1;

		//초기 상태
		memset(visit, 0, sizeof(visit));
		q.push({ ty,tx });
		visit[ty][tx] = 1;
		dist = 0;
		flag = 0;
		v.clear();

		//목적지 까지 이동
		while (1) {
			dist++;
			int len = q.size();
			while (len--) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[ny][nx] || map[ny][nx] == 1) continue;
					if (map[ny][nx] == -1) {
						flag = 1;
						break;
					}
					q.push({ ny,nx });
					visit[ny][nx] = 1;
				}
				if (flag == 1) break;
			}
			if (flag == 1) break;
		}
		fuel -= dist;
		if (fuel < 0) return;
		fuel += (dist * 2);

		//도착지 정보 초기화
		map[destY][destX] = 0;
		ty = destY;
		tx = destX;
	}
}

int main(int argc, char** argv)
{
	cin >> N >> K;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	for (int i = 0; i < K; i++) {
		info temp;
		cin >> temp.x >> temp.y >> temp.xx >> temp.yy;
		map[temp.y][temp.x] = 10 + i;
		c.push_back(temp);
	}
	cin >> tx >> ty >> fuel;
	solve();
	if (fuel <= 0) fuel = -1;
	cout << fuel << '\n';
	cout << endl;
	return 0;
}
