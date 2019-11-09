#include<iostream>
//#define DEB
using namespace std;

struct Location {
	int r;
	int c;
};

int dx[4] = { 0,0,-1,+1 };
int dy[4] = { -1,+1,0,0 };

Location Aircon[2];
int R;
int C;
int T;
int map[50][50];
int sum=0;
int deltaMap[50][50] = { 0, };

void delta() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				int cnt = 0;
				int temp = map[i][j] / 5;
				if (temp == 0) continue;
				else {
					for (int k = 0; k < 4; k++) {
						if (i + dy[k] >= 0 && i + dy[k] < R && j + dx[k] >= 0 && j + dx[k] < C)
								if(map[i + dy[k]][j + dx[k]] != -1) {
									deltaMap[i + dy[k]][j + dx[k]] += temp;
									cnt++;
						}
					}
				}
				deltaMap[i][j] -= temp*cnt;
			}
		}
	}
}

void update() {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] += deltaMap[i][j];
			deltaMap[i][j] = 0;
		}
	}
}




void clean() {
	//위 청소

	for (int i = Aircon[0].r - 1; i > 0; i--) {
		map[i][0] = map[i - 1][0];
	}
	for (int i = 0; i <C-1; i++) {
		map[0][i] = map[0][i+1];
	}
	for (int i = 0; i <Aircon[0].r; i++) {
		map[i][C-1] = map[i+1][C-1];
	}
	for (int i = C-1 ; i > Aircon[0].c; i--) {
		map[Aircon[0].r][i] = map[Aircon[0].r][i-1];
	}
	map[Aircon[0].r][Aircon[0].c + 1] = 0;

	//아래 청소

	for (int i = Aircon[1].r + 1; i < R-1; i++) {
		map[i][0] = map[i + 1][0];
	}
	for (int i = 0; i <C-1; i++) {
		map[R-1][i] = map[R-1][i + 1];
	}
	for (int i = R-1; i >Aircon[1].r; i--) {
		map[i][C - 1] = map[i - 1][C - 1];
	}
	for (int i = C - 1; i > Aircon[1].c; i--) {
		map[Aircon[1].r][i] = map[Aircon[1].r][i - 1];
	}
	map[Aircon[1].r][Aircon[1].c + 1] = 0;

}

int main() {

	cin >> R >> C >> T;
	 
	int AirconCnt = 0;

	for (int i = 0; i < R; i++) {

		for (int j = 0; j < C; j++) {

			cin >> map[i][j];

			if (map[i][j] == -1) {
				Aircon[AirconCnt].r = i;
				Aircon[AirconCnt].c = j;
				AirconCnt++;
			}

		}

	}



	for (int i = 0; i < T; i++) {
		delta();
		
#ifdef DEB
		cout << i<<"번째 delta"<<endl;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout<<deltaMap[i][j]<<' ';
			}
			cout << endl;
		}

#endif // DEB
		

		update();
		
		
#ifdef DEB
		cout << i << "번째 update" << endl;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}

#endif // DEB

		clean();

#ifdef DEB
		cout << i << "번째 clean" << endl;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}

#endif // DEB


	}



	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == -1) {
				continue;
			}
			sum += map[i][j];
		}
	}

	cout << sum;

	return 0;
}