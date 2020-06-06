#include<iostream>
#include<vector>
#include<cstring>

#define UP 0;
#define DOWN 1;
#define LEFT 2;
#define RIGHT 3;
#define BASE 2000;

using namespace std;

struct Info {
	int x;
	int y;
	int K;
	int dir;
	bool alive;
};


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0, 0 };

int nextMap[4001][4001];
int total;
int N;
Info tempAtom;
vector <Info> atom;
int cnt=0;
void move() {
	cnt++;
	for (int i = 0; i < atom.size(); i++) {
		atom[i].y += dy[atom[i].dir];
		atom[i].x += dx[atom[i].dir];

		if (atom[i].y > 4000 || atom[i].y < 0 || atom[i].x < 0 || atom[i].x >4000) {
			atom[i].alive = false;
			atom.erase(atom.begin() + i);
			i--;
		}
		else if (nextMap[atom[i].y][atom[i].x] ==-1) {
			nextMap[atom[i].y][atom[i].x] = i;
		}
		else if(nextMap[atom[i].y][atom[i].x] >= 0){
			atom[nextMap[atom[i].y][atom[i].x]].alive = false;
			atom[i].alive = false;
			total += atom[nextMap[atom[i].y][atom[i].x]].K;
			total += atom[i].K;
			nextMap[atom[i].y][atom[i].x] = -2; //3개 이상 초과 충돌 판단용 -2
		}
		else if (nextMap[atom[i].y][atom[i].x] == -2) {
			atom[i].alive = false;
			total += atom[i].K;
		}
	}
}

void update() {

	for (int i = 0; i < atom.size(); i++) {
		nextMap[atom[i].y][atom[i].x] = -1;
		if (atom[i].alive == false) {
			atom.erase(atom.begin() + i);
			i--;
		}
	}
}

void solve() {
	while (!atom.empty())
	{
		move();
		update();
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	memset(nextMap, -1, sizeof(nextMap));
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		atom.clear();
		total = 0;

		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp; tempAtom.x = 2000 + (temp*2);
			cin >> temp; tempAtom.y = 2000 - (temp*2);
			cin >> temp; tempAtom.dir = temp;
			cin >> temp; tempAtom.K = temp;
			tempAtom.alive = true;
			atom.push_back(tempAtom);
		}
		solve();
		cout << '#' << test_case << ' ' << total << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
