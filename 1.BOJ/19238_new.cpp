#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

#define EMPTY 0
#define PERSON 2
#define WALL 1
#define PRINT_ARR(n,m, target)	for(int i = 0; i < n; i++){ \
								for(int j = 0; j < m; j++){ \
									cout << target << ' '; \
								} \
								cout <<'\n';\
							}

using namespace std;

int N, M, fuel;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

int ty, tx; // 택시 현재 위치

struct P {  // 위치 정보( 0: 도로, 1: 벽, 2: 승객 / 승객일 경우 dest(y,x) 값 존재)
	int state = 0;
	pair<int, int> dest;
};

P tempP;
vector < vector <P> > board(22, vector <P>(22, tempP));  //맵

int visit[20][20];

int isEdge(int y, int x) {
	return y < 0 || x < 0 || y >= N || x >= N || board[y][x].state == WALL;
}

int findPerson() {
	queue<pair<int, int>> q;
	q.push({ ty, tx });
	if (board[ty][tx].state == PERSON) {   //현재위치에 승객이 있으면 승객을 지우고 바로 리턴
		board[ty][tx].state = EMPTY;
		return 0;
	}
	int fy = 100, fx = 100;    // 찾은 승객의 좌표
	int found = 0;			// 승객 찾았는지 확인 플래그
	int dist = 0;			// 승객까지의 거리
	while (!q.empty()) {
		dist++;
		int size = q.size();
		while (size--) {
			auto cur = q.front();
			q.pop();
			int y = cur.first;
			int x = cur.second;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (isEdge(ny, nx) || visit[ny][nx]) continue;
				if (board[ny][nx].state == PERSON) {
					found = 1;
					visit[ny][nx] = 1;
					if (ny < fy) {
						fy = ny;
						fx = nx;;
					}
					else if (ny == fy) {
						if (nx < fx) {
							fy = ny;
							fx = nx;
						}
					}
				}
				else if (board[ny][nx].state == EMPTY) {
					q.push({ ny, nx });
					visit[ny][nx] = 1;
				}
			}
		}
		if (found) break;
	}
	if (found == 0) return 1;
	tx = fx, ty = fy;  // 택시위치 갱신
	board[ty][tx].state = EMPTY;  // 승객 지우기
	fuel -= dist;
	return 0;
}

int toHome() {  //승객 찾는 로직이랑 거의 유사
	queue<pair<int, int>> q;
	q.push({ ty, tx });
	if (board[ty][tx].dest.first == ty && board[ty][tx].dest.second == tx) {  // 현재위치와 집의 좌표가 같으면 바로 리턴
		return 0;
	}
	int targetY = board[ty][tx].dest.first;   //승객의 집 좌표
	int targetX = board[ty][tx].dest.second;
	int found = 0;
	int dist = 0;
	while (!q.empty()) {
		dist++;
		int size = q.size();
		while (size--) {
			auto cur = q.front();
			q.pop();
			int y = cur.first;
			int x = cur.second;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (isEdge(ny, nx) || visit[ny][nx]) continue;
				if (ny == targetY && nx == targetX) {  // 집 찾으면 끝내기
					found = 1;
					break;
				}
				else{
					q.push({ ny, nx });
					visit[ny][nx] = 1;
				}
			}
			if (found) break;
		}
		if (found) break;
	}
	if (found == 0) return 1;
	tx = targetX, ty = targetY;
	fuel -= dist;
	return 0;
}

int main() {
	cin >> N >> M >> fuel;
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j].state;
		}
	}
	cin >> ty >> tx;
	ty--; tx--;  // 인덱스 0번부터 시작
	int tempX, tempY;
	for (int i = 0; i < M; i++) {
		cin >> tempY >> tempX;
		tempY--; tempX--; // 인덱스 0번부터 시작
		board[tempY][tempX].state = 2;
		cin >> board[tempY][tempX].dest.first >> board[tempY][tempX].dest.second;
		board[tempY][tempX].dest.first--; // 인덱스 0번부터 시작
		board[tempY][tempX].dest.second--; // 인덱스 0번부터 시작
	}


	//PRINT_ARR(N, N, board[i][j].state)
	//PRINT_ARR(N, N, '(' << board[i][j].dest.first << ',' << board[i][j].dest.second << ')')

	int flag = 0;
	int cnt = M;

	// cout << "-------------------" << endl;
	while (fuel >= 0 && cnt) {
		cnt--;
		memset(visit, 0, sizeof(visit));
		// cout << "출발위치 :" << ty << "," << tx << endl;
		flag = findPerson();
		//cout << "승객위치 :" << ty << "," << tx << endl;
		//cout << "승객위치에서 남은 연료 :" << fuel << endl;
		if (flag || fuel < 0) break;
		memset(visit, 0, sizeof(visit));
		int startFuel = fuel;
		flag = toHome();
		//cout << "도착지 :" << ty << "," << tx << endl;
		//cout << "도착지에서 남은 연료 :" << fuel << endl;
		if (flag || fuel < 0) break;
		fuel += (startFuel - fuel) * 2;
		//cout << "충전 후 연료 :" << fuel << endl;
		//cout << "-------------------" << endl;
	}
	if (fuel < 0 || flag) cout << -1;
	else cout << fuel;
}
