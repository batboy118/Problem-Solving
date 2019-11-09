#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

struct StairInfo {
	int x, y;
	int time;
	int numOfUsing;
};

struct PersonInfo {
	int x, y;
	int stair0_dist;
	int stair1_dist;
};

int N;
int num;
int tempInput;
int result;
int numS;
int cnt0, cnt1;
StairInfo S[2];
PersonInfo P[10];
int WAIT0[10];
int WAIT1[10];

int S0[10];
int S1[10];

void calDist() {
	for(int i =0; i<num ;i++)
		{
			P[i].stair0_dist = abs(P[i].x-S[0].x) + abs(P[i].y - S[0].y);
			P[i].stair1_dist = abs(P[i].x - S[1].x) + abs(P[i].y - S[1].y);
		}
}

void calTime() {
	sort(S0, S0 + cnt0);
	sort(S1, S1 + cnt1);

	int timeCnt = 0;
	int idx0 = 0; int idx1 = 0;
	bool flag = false;

	while (!flag)
	{
		if (idx0 == cnt0 &&idx1 == cnt1 && S[0].numOfUsing==0 && S[1].numOfUsing == 0) { flag = true; break; }
		timeCnt++;
		
		for (int i = S[0].numOfUsing; i > 0; i--) {
			WAIT0[idx0 - i]--;
			if (WAIT0[idx0 - i] == 0) S[0].numOfUsing--;
		}
		for (int i = S[1].numOfUsing; i > 0; i--) {
			WAIT1[idx1 - i]--;
			if (WAIT1[idx1 - i] == 0) S[1].numOfUsing--;
		}
		
		if(S0[idx0] < timeCnt && S[0].numOfUsing<3 && idx0 < cnt0) {
			idx0++;
			S[0].numOfUsing++;
			if (S0[idx0] < timeCnt && S[0].numOfUsing<3 && idx0 < cnt0) {
				idx0++;
				S[0].numOfUsing++;
				if (S0[idx0] < timeCnt && S[0].numOfUsing < 3 && idx0 < cnt0) {
				idx0++;
				S[0].numOfUsing++;
				}
			}
		}

		if (S1[idx1] < timeCnt && S[1].numOfUsing<3 && idx1<cnt1) {
			idx1++;
			S[1].numOfUsing++;
			if (S1[idx1] < timeCnt && S[1].numOfUsing<3 && idx1 < cnt1) {
				idx1++;
				S[1].numOfUsing++;
				if (S1[idx1] < timeCnt && S[1].numOfUsing < 3 && idx1 < cnt1) {
					idx1++;
					S[1].numOfUsing++;
				}
			}
		}
	}

	if (result > timeCnt) result = timeCnt;
}

void solve() {
	
	for (int i = 0; i < (1 << num); i++) {
		cnt0 = 0;
		cnt1 = 0;
		for (int j = 0; j < num; j++) {
			if (i & (1 << j)) {
		//		S0[cnt0][1] = j;
				S0[cnt0] = P[j].stair0_dist;
				WAIT0[cnt0]=S[0].time;
				cnt0++;
			}
			else
			{
		//		S1[cnt1][1] = j;
				S1[cnt1] = P[j].stair1_dist;
				WAIT1[cnt1] = S[1].time;
				cnt1++;
			}
		}
		calTime();
	}

	
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		num = 0;
		numS = 0;
		result = 987654321;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> tempInput;
				if (tempInput==1) {
					P[num].x = j;
					P[num].y = i;
					num++;
				}
				else if (tempInput > 1) {
					S[numS].x = j;
					S[numS].y = i;
					S[numS].time = tempInput;
					S[numS].numOfUsing = 0;
					numS++;
				}
			}
		}
		
		calDist();
		solve();
	
		cout << '#'<<test_case <<' ' <<result<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}