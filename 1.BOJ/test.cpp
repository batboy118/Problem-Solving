#include <iostream>

using namespace std;

int ans = 0;
int dice[10];
int mal[4] = { 0, }; //말의 위치를 기록
int map[33] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,13,16,19,22,24,28,27,26,25,30,35,40,0 };
bool visit[33] = { 0, };

void dfs(int turn, int score) {

	if (turn == 10) {
		if (score > ans) ans = score;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int pre = mal[i];
		int cur = mal[i]; //현재 말의 출발 위치
		int size = dice[turn];

		///파란 화살표 이동 조작
		if (cur == 5) {
			cur = 20;
			size--;
		}
		else if (cur == 10) {
			cur = 23;
			size--;
		}
		else if (cur == 15) {
			cur = 25;
			size--;
		}

		//이동
		while (size--) {
			if (cur == 19) {
				cur = 31;//40
			}
			else if (cur == 22) {
				cur = 28; //25
			}
			else if (cur == 24) {
				cur = 28; //25

			}
			else if (cur == 27) {
				cur = 28; //25

			}
			else {
				cur++;
			}
		}

		if (cur > 31) cur = 32; //도착

		if (visit[cur] && cur < 32) continue;

		visit[pre] = 0;
		visit[cur] = 1;
		mal[i] = cur;
		dfs(turn + 1, score + map[cur]);
		mal[i] = pre;
		visit[pre] = 1;
		visit[cur] = 0;
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}

	dfs(0,0);
	cout << ans << "\n";
	return 0;
}
