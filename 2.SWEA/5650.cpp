#include<iostream>
#include<cmath>
using namespace std;

//#define DEBUG

//장애물
#define UP_RIGHT 1
#define DOWN_RIGHT 2
#define DOWN_LEFT 3
#define UP_LEFT 4
#define SQUARE 5
#define W1 6
#define W2 7
#define W3 8
#define W4 9
#define W5 10
#define BLACKHOLE -1

//진행 방향 index
#define UP 2
#define DOWN 0
#define RIGHT 1
#define LEFT 3

struct Info {
	int x1, y1;
	int x2, y2;
	int cnt = 0;
};

Info Wormhole[11];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int N;
int Map[101][101];
int Score = 0;
int temp;
int nowX, nowY;
int dir;
bool Flag; 
int test_case;

void Move() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (Map[i][j] != 0)continue;

			for (int startDir = 0; startDir < 4; startDir++) {
				nowX = j; nowY = i;
				dir = startDir;
				temp = 0;
				int ccc = 0;
				Flag = true;
				if (nowX + dx[dir] < 0 || nowX + dx[dir]> N - 1 || nowY + dy[dir]<0 || nowY + dy[dir]>N - 1) continue;

				while (Flag) {

				
#ifdef DEBUG
					ccc++;
					cout << i << ' ' << j << ' ' << ccc << "번째 : " << nowX << ", " << nowY << endl;
#endif					
					nowX += dx[dir];
					nowY += dy[dir];
					if (Map[nowY][nowX] == BLACKHOLE || (nowY == i && nowX == j)) Flag = false;

					//벽
					else if (nowX<0 || nowX>N - 1 || nowY<0 || nowY>N - 1) {
						temp++;
						dir = (dir + 2) % 4;
					}
					//네모블럭
					else if (Map[nowY][nowX] == SQUARE) {
						temp++;
						dir = (dir + 2) % 4;
					}
					//1~4블럭
					else if(Map[nowY][nowX] >= 1&& Map[nowY][nowX] <=4 ){
						if (Map[nowY][nowX] == UP_RIGHT) {
							temp++;
							if (dir == DOWN) {
								dir = RIGHT;
								}
							else if (dir == LEFT) {
								dir = UP;
							}
							else {
								dir = (dir + 2) % 4;
							}
						}
						else if (Map[nowY][nowX] == DOWN_RIGHT) {
							temp++;
							if (dir == LEFT) {
								dir = DOWN;
							}
							else if (dir == UP) {
								dir = RIGHT;
							}
							else {
								dir = (dir + 2) % 4;
							}
						}
						else if (Map[nowY][nowX] == DOWN_LEFT) {
							temp++;
							if (dir == RIGHT) {
								dir = DOWN;
							}
							else if (dir == UP){
								dir = LEFT;
							}
							else {
								dir = (dir + 2) % 4;
							}
						}
						else if (Map[nowY][nowX] == UP_LEFT) {
							temp++;
							if (dir == RIGHT) {
								dir = UP; 
							}
							else if (dir == DOWN) {
								dir = LEFT;
							}
							else {
								dir = (dir + 2) % 4;
							}
						}
					}
					//웜홀
					else if (Map[nowY][nowX] >= W1 && Map[nowY][nowX] <= W5) {
						int WormNo = Map[nowY][nowX];
						if (Wormhole[WormNo].x1 == nowX && Wormhole[WormNo].y1 == nowY) {
							nowX = Wormhole[WormNo].x2;
							nowY = Wormhole[WormNo].y2;
						}
						else {
							nowX = Wormhole[WormNo].x1;
							nowY = Wormhole[WormNo].y1;
						}
					}
					
					
				}
#ifdef DEBUG
				cout <<test_case<< "############################### " << temp << endl;
#endif		

				if (Score < temp) Score = temp;
			}

		}
	}
}

int main(int argc, char** argv)
{
	
	int T;
	freopen("input.txt", "r", stdin);//////////////////////////////////////////////////////
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		for (int i = 6; i <= 10; i++) {
			Wormhole[i].cnt = 0;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Map[i][j];
				if (Map[i][j] <= 10 && Map[i][j] >= 6) {
					if (Wormhole[Map[i][j]].cnt == 0) {
						Wormhole[Map[i][j]].cnt++;
						Wormhole[Map[i][j]].x1 = j;
						Wormhole[Map[i][j]].y1 = i;
					}
					else {
						Wormhole[Map[i][j]].cnt++;
						Wormhole[Map[i][j]].x2 = j;
						Wormhole[Map[i][j]].y2 = i;
					}
				}
			}
		}
		Score = 0;

		Move();

		cout << "#" << test_case << ' ' << Score << endl;

	}
	return 0;
}