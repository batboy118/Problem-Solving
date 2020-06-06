#include<iostream>
#include<algorithm>
#include<functional>
#include<iomanip>

#define STAY 0
#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

using namespace std;

int result;
int M, N;
struct Maninfo {
	int x, y;
};

struct BCinfo {
	int x, y;
	int map[11][11];
	int power;
	int cover;
};
int dx[5] = { 0,0,1,0,-1 };
int dy[5] = { 0,-1,0,1,0 };

Maninfo A[101];
Maninfo B[101];

BCinfo BC[9];

void Covercheck(int i, int cnt, int x, int y) {
	BC[i].map[x][y] = BC[i].power;
	if (cnt < BC[i].cover) {
		if (x + dx[UP] >= 1&& x + dx[UP] <= 10 && y + dy[UP] >= 1 && y + dy[UP] <= 10) {
			cnt++;
			Covercheck(i, cnt, x + dx[UP], y + dy[UP]);
			cnt--;
		}
		if (x + dx[RIGHT] >= 1 && x + dx[RIGHT] <= 10 && y + dy[RIGHT] >= 1 && y + dy[RIGHT] <= 10) {
			cnt++;
			Covercheck(i, cnt, x + dx[RIGHT], y + dy[RIGHT]);
			cnt--;
		}
		if (x + dx[DOWN] >= 1 && x + dx[DOWN] <= 10 && y + dy[DOWN] >= 1 && y + dy[DOWN] <= 10) {
			cnt++;
			Covercheck(i, cnt, x + dx[DOWN], y + dy[DOWN]);
			cnt--; 
		}
		if (x + dx[LEFT] >= 1 && x + dx[LEFT] <= 10 && y + dy[LEFT] >= 1 && y + dy[LEFT] <= 10) {
			cnt++;
			Covercheck(i, cnt, x + dx[LEFT], y + dy[LEFT]);
			cnt--;
		}
	}
	return;
}

void Cal() {
	int maxA=0;
	int maxB=0;
	int tempA = 0;
	int tempB = 0;
	int checkA = 0;
	int checkB = 0;
	for (int i = 0; i <= M; i++) {
		checkA = 0;
		checkB = 0;
		maxA = 0;
		maxB = 0;
		for (int j = 1; j <= N; j++) {
			tempA = BC[j].map[A[i].x][A[i].y];
			tempB = BC[j].map[B[i].x][B[i].y];
			if (maxA < tempA) {
				maxA = tempA;
				checkA = j;
			}
			if (maxB < tempB) {
				maxB = tempB;
				checkB = j;
			}
		}
		if(checkA==checkB ){
			int temp1[10] = { 0, };
			int tempcnt1 = 0;
			int temp2[10] = { 0, };
			int tempcnt2 = 0;
			for (int j = 1; j <= N; j++) {
				if (BC[j].map[A[i].x][A[i].y] != 0) {
					temp1[tempcnt1] = BC[j].map[A[i].x][A[i].y];
					tempcnt1++;
				}
				if (BC[j].map[B[i].x][B[i].y] != 0 ) {
					temp2[tempcnt2] = BC[j].map[B[i].x][B[i].y];
					tempcnt2++;
				}
			}
			sort(temp1, temp1 + tempcnt1, greater<int>());
			sort(temp2, temp2 + tempcnt2, greater<int>());
			if (tempcnt2 >= 1 && tempcnt1 >= 1) {
				if (maxA + temp2[1] > maxB + temp1[1]) {
					result += (maxA + temp2[1]);
				}
				else {
					result += (maxB + temp1[1]);
				}
			}
			else if (tempcnt1 < 1) {
				result += (maxA + temp2[1]);
			}
			else {
				result += (maxB + temp1[1]);
			}
			
		}
		else {
			result += (maxA + maxB);
			maxA = 0;
			maxB = 0;
		}
	}
	return;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("sample_input (1).txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		A[0].x = 1;
		A[0].y = 1;
		B[0].x = 10;
		B[0].y = 10;
		int dir;
		cin >> M >> N;
		for (int i = 1; i <= M; i++) { 			
			cin >> dir;
			A[i].x = A[i - 1].x + dx[dir];
			A[i].y = A[i - 1].y + dy[dir];
		}
		for (int i = 1; i <= M; i++) BC[i].map[x][y] = BC[i].power;
			cin >> dir;
			B[i].x = B[i - 1].x + dx[dir];
			B[i].y = B[i - 1].y + dy[dir];
		}
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt = 0;
			cin >> BC[i].x >> BC[i].y >> BC[i].cover >> BC[i].power;
			for (int j = 0; j <= 10; j++) {
				for (int k = 0; k <= 10; k++)
					BC[i].map[j][k] = 0;
			}
			Covercheck(i, cnt, BC[i].x, BC[i].y);
		}
		Cal();
		cout << '#' << test_case << ' ' << result<<'\n';
		result = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}