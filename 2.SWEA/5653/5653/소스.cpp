#include<iostream>
#include<vector>
#include<algorithm>



//#define DEB

#define Disabled 2
#define Activate 1
#define Empty 0
#define Dead -1


using namespace std;

struct Info {
	int x, y, state, time;
	int cnt;
};

int AliveCount;
int timeCount;
int Space[450][450];
int K, N, M;
Info tempSepo;
vector <Info> Sepo;

bool cmp(const Info& x, const Info& y) {
	return x.time > y.time;

}

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };


void Spread(int idx) {

		for (int j = 0; j < 4; j++) {
			if (Space[Sepo[idx].y + dy[j]][Sepo[idx].x + dx[j]] == Empty) {
				Space[Sepo[idx].y + dy[j]][Sepo[idx].x + dx[j]] = Sepo[idx].time;
				tempSepo.x = Sepo[idx].x + dx[j];
				tempSepo.y = Sepo[idx].y + dy[j];
				tempSepo.state = Disabled;
				tempSepo.time = Sepo[idx].time;
				tempSepo.cnt = 0;
				Sepo.push_back(tempSepo);
				AliveCount++;
			}
		}

}


void AfterOnehour() {

	int xx= AliveCount;

	for (int i = 0; i < xx; i++) {
		if (Sepo[i].cnt == Sepo[i].time && Sepo[i].state == Activate) {
			Spread(i);
		}

		Sepo[i].cnt++;

		if (Sepo[i].cnt == Sepo[i].time && Sepo[i].state == Disabled ) {
			Sepo[i].state = Activate;
		}


		else if (Sepo[i].cnt == 2 * Sepo[i].time && Sepo[i].state == Activate) {
			Sepo[i].state = Dead;
			Sepo[i].time = -1;
			AliveCount--;
		}
	}

}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 400; i++) {
			for (int j = 0; j < 400; j++) {
				Space[i][j] = 0;
			}
		}
		cin >> N >> M >> K;
		AliveCount = 0;
		Sepo.clear();

		for (int i = 200; i < 200 + N; i++) {
			for (int j = 200; j < 200 + M; j++) {
				cin >> Space[i][j];
				if (Space[i][j] != Empty) {
					tempSepo.x = j;
					tempSepo.y = i;
					tempSepo.state = Disabled;
					tempSepo.time = Space[i][j];
					tempSepo.cnt = 0;
					Sepo.push_back(tempSepo);
					AliveCount++;
				}
			}
		}

#ifdef DEB   //입력 확인
		cout << "# 입력 확인 #" << endl;
		for (int i = 200; i <200 + N; i++) {
			for (int j = 200; j <200 + M; j++) {
				cout << Space[i][j] <<' ';
			}
			cout << endl;
		}
#endif
		for (timeCount = 1; timeCount <= K; timeCount++) {
			for (int i = 0; i < Sepo.size(); i++) {
				if (Sepo[i].state == Dead) Sepo.erase(Sepo.begin()+i);
			}
			sort(Sepo.begin(), Sepo.end(), cmp);
			AfterOnehour();

#ifdef DEB   
			cout << timeCount << "시간 후" << endl;
			for (int i = 190; i < 210; i++) {
				for (int j = 190; j < 210; j++) {
					cout << Space[i][j] << ' ';
				}
				cout << endl;
			}
#endif
		}

		cout <<'#'<<test_case<<' '<<AliveCount<< endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}