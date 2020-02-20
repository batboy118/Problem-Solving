#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

#define STAY 0
#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4
#define endl '\n'
using namespace std;


struct InfoAP {
	int x, y;
	int C, P;
};

struct InfoMan {
	int x, y;
	int numOfAP;
	int POWER[4];
};

int dx[5] = { 0,0,1,0,-1 };
int dy[5] = { 0,-1,0,1,0 };
int M, A;
int result;
int temp;
int map[11][11][5];
InfoAP tempAP;
vector <InfoAP> AP;
InfoMan Man[2]; 
queue <int> man1Move;
queue <int> man2Move;
vector <int, int> man1Power;
vector <int, int> man2Power;
int maxA, maxB;


bool compare(pair<int, int> a,
	pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first > b.first;
	}
}

void cal() {

	for (int i = 0; i < 2; i++) {
		if (map[Man[i].x][Man[i].y][4] > 0) {
			Man[i].numOfAP = map[Man[i].x][Man[i].y][4];
			for (int j = 0; j < 4; j++) {
				if (map[Man[i].x][Man[i].y][j] > 0) {
					Man[i].POWER[j] = map[Man[i].x][Man[i].y][j];
					if (i == 0)
						man1Power.push_back(make_pair(Man[i].POWER[j], j));
					else
						man2Power.push_back(make_pair(Man[i].POWER[j], j));
				}
				else {
					Man[i].POWER[j] = 0;
				}
			}
		}
	}

	sort(man1Power.begin(), man1Power.end(), compare);
	sort(man2Power.begin(), man2Power.end(), compare);

	if (man1Power.empty() && man2Power.empty()) {}
	else if (!man1Power.empty() && man2Power.empty()) { result += man1Power[0].first; }
	else if (man1Power.empty() && !man2Power.empty()) { result += man2Power[0].first; }
	else
	{
		if (man1Power[0].second != man2Power[0].second) {
			result += man1Power[0].first;
			result += man2Power[0].first;
		}
		else {
			if (man1Power.size() == 1 && man2Power.size() == 1) {
				result += man1Power[0].first;
			}
			else if (man1Power.size() == 1 && man2Power.size() > 1) {
				result += man1Power[0].first;
				result += man2Power[1].first;
			}
			else if (man1Power.size() > 1 && man2Power.size() == 1) {
				result += man1Power[1].first;
				result += man2Power[0].first;
			}
			else
			{
				if (man1Power[1].second > man2Power[1].second) {
					result += man1Power[1].first;
					result += man2Power[0].first;
				}
				else {
					result += man1Power[0].first;
					result += man2Power[1].first;
				}
			}
		}

		man1Power.clear();
		man2Power.clear();
	}
}

void Move() {
	Man[0].x += dx[man1Move.front()];
	Man[0].y += dy[man1Move.front()];
	Man[1].x += dx[man2Move.front()];
	Man[1].y += dy[man2Move.front()];
	man1Move.pop();
	man2Move.pop();
}

void coverMap() {
	for (int i = 0; i < AP.size(); i++) {
		for (int k = AP[i].x - AP[i].C; k <= AP[i].x + AP[i].C; k++) {
			for (int j = AP[i].y - AP[i].C; k <= AP[i].y + AP[i].C; j++) {
				if (abs(AP[i].x - k) + abs(AP[i].y - j) <= AP[i].C) {
					map[j][k][i] = AP[i].P;
					map[j][k][4]++;
				}
			}
		}
	}
	
	
	/*
	또는 깊이를 범위값으로 제한하고 재귀로 구하기.
	*/
}

void solve() {
	
	coverMap();

	for (int i = 0; i < M; i++) {
		Move();
		cal();
	}

}


int main(int argc, char** argv){
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;


	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> M >> A;

		Man[0].x = 1; Man[0].y = 1;
		Man[1].x = 10; Man[1].y = 10;
		result = 0;

		memset(map, -1, sizeof(map));


		for (int i = 0; i < M; i++) {
			cin >> temp;
			man1Move.push(temp);
		}

		for (int i = 0; i < M; i++) {
			cin >> temp;
			man2Move.push(temp);
		}

		for (int i = 0; i < A; i++) {
			cin >> temp; tempAP.x = temp;
			cin >> temp; tempAP.y = temp;
			cin >> temp; tempAP.C = temp;
			cin >> temp; tempAP.P = temp;
		}

		solve();

		cout << '#' << test_case << ' ' << result<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}