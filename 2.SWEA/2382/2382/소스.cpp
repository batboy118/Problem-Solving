#include<iostream>
#define MAX 100
#define EDGE -1
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define DEB


using namespace std;

struct Info {
	int x, y;
	int quantity;
	int dir;
	int nx;
	int ny;
};

Info Gunzip[1000];
Info tempGunzip;

int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,-1,1,0,0 };

int N;
int K;
int M;
int result;
int mapBiger[MAX][MAX];
int mapTotal[MAX][MAX];


void make_next_location() {
	for (int i = 0; i < K; i++) {
		Gunzip[i].x += dx[Gunzip[i].dir];
		Gunzip[i].y += dy[Gunzip[i].dir];
	}
}

void update_Gunzip(){
	for (int i = 0; i < K; i++) {
		if (mapTotal[Gunzip[i].y][Gunzip[i].x] > Gunzip[i].quantity && Gunzip[i].quantity > 0) {
			Gunzip[i].quantity = mapTotal[Gunzip[i].y][Gunzip[i].x];
		}
	}
}

void init_Map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
				mapBiger[i][j] = EDGE;
				mapTotal[i][j] = EDGE;
			}
			else {
				mapTotal[i][j] = 0;
				mapTotal[i][j] = 0;
			}
		}
	}
}

void cal_result() {
	result = 0;
	for (int i = 0; i < K; i++) {
		if (Gunzip[i].quantity>0) {
			result += Gunzip[i].quantity;
		}
	}
}

bool check_EDGE(int i) {
	if (Gunzip[i].x <= 0 || Gunzip[i].x >= N - 1 || Gunzip[i].y >= N - 1 || Gunzip[i].y <= 0) return true;
	else return false;
}

void solve() {

	for (int time = 0; time < M; time++) {

#ifdef DEB
		cout << "## Biger Map ## : " << M << "시간" << endl;
		for (int i = 0; i < N; i++) {
			
			for (int j = 0; j < N; j++) {
				cout << mapBiger[i][j]<<' ';
			}
			cout << endl;
		}

#endif

#ifdef DEB
		cout << "## Total Map ## : " << M << "시간" << endl;
		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {
				cout << mapTotal[i][j] << ' ';
			}
			cout << endl;
		}

#endif

		init_Map();
		make_next_location();
		
		for (int i = 0; i < K; i++) {
			if (Gunzip[i].quantity > 0) {
				if (check_EDGE(i)) {
					Gunzip[i].quantity = Gunzip[i].quantity / 2;
					if (Gunzip[i].quantity == 0) Gunzip[i].dir = 0;
					else if (Gunzip[i].dir == UP) Gunzip[i].dir = DOWN;
					else if (Gunzip[i].dir == DOWN) Gunzip[i].dir = UP;
					else if (Gunzip[i].dir == RIGHT) Gunzip[i].dir = LEFT;
					else if (Gunzip[i].dir == LEFT) Gunzip[i].dir = RIGHT;
				}
				else {
					if (mapTotal[Gunzip[i].y][Gunzip[i].x] > 0) {
						mapTotal[Gunzip[i].y][Gunzip[i].x] += Gunzip[i].quantity;
						if (Gunzip[mapBiger[Gunzip[i].y][Gunzip[i].x]].quantity < Gunzip[i].quantity) {
							Gunzip[mapBiger[Gunzip[i].y][Gunzip[i].x]].quantity = 0;
							Gunzip[mapBiger[Gunzip[i].y][Gunzip[i].x]].dir = 0;
							mapBiger[Gunzip[i].y][Gunzip[i].x] = i;
						}
						else {
							Gunzip[i].quantity = 0;
							Gunzip[i].dir = 0;
						}
					}
					else {
						mapTotal[Gunzip[i].y][Gunzip[i].x] += Gunzip[i].quantity;
						mapBiger[Gunzip[i].y][Gunzip[i].x] = i;
					}
				}
			}
		}
		update_Gunzip();
	}
	cal_result();
}

int main() {

	int T;
	
	cin >> T;


	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M >> K;

		int temp;
		for (int i = 0; i < K; i++) {
			cin >> temp; Gunzip[i].y=temp;
			cin >> temp; Gunzip[i].x = temp;
			cin >> temp; Gunzip[i].quantity = temp;
			cin >> temp; Gunzip[i].dir = temp;
		}

		solve();

		cout << '#' << test_case << ' ' << result<<'\n';
	}
	return 0;
}