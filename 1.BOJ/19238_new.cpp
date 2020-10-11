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
int ty, tx;
struct P {
	int state = 0;
	pair<int, int> dest;
};
P tempP;
vector < vector <P> > board(20, vector <P> (20, tempP)) ;
int visit[20][20];

int findPerson() {
	queue<pair<int, int>> q;
	q.push({ty, tx});
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

	}
}

int toHome() {

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
	ty--; tx--;
	int tempX, tempY;
	for (int i = 0; i < M; i++) {
		cin >> tempY >> tempX;
		tempY--; tempX--;
		cin >> board[tempY][tempX].dest.first;
		cin >> board[tempY][tempX].dest.second;
	}


	PRINT_ARR(N, N, board[i][j].state)   //
	PRINT_ARR(N, N, '(' << board[i][j].dest.first << ',' << board[i][j].dest.first << ')')   //

	int flag = 0;
	int cnt = M;
	while (fuel > 0 || flag == 0 || cnt) {
		cnt--;
		memset(visit, 0, sizeof(visit));
		flag = findPerson();
		if (flag) break;
		memset(visit, 0, sizeof(visit));
		toHome();
	}
	if (fuel < 0 || cnt) cout << -1;
	else cout << fuel;
}
