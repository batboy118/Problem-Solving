#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

#define PRINT_ARR(n, target) for(int i = 0; i < n; i++){ \
								cout << target << ' '; \
							} \
							cout <<'\n';\

#define PRINT_ARR2(n,m, target)	for(int i = 0; i < n; i++){ \
								for(int j = 0; j < m; j++){ \
									cout << target << ' '; \
								} \
								cout <<'\n';\
							}\
							cout << "========================================"<<endl;
using namespace std;

int r, c, k;
int B[100][100];
int r_max = 3;
int c_max = 3;

struct N{
	int cnt;
	int number;
};

bool cmp(const N& p1, const N& p2) {
	if (p1.cnt < p2.cnt) {
		return true;
	}
	else if (p1.cnt > p2.cnt) {
		return false;
	}
	else {
		return p1.number < p2.number;
	}
}

void R() {
	//좌측 밀기(필요 없을 수도,,)
	for (int i = 0; i < r_max; i++) {
		for (int j = 0; j < c_max; j++) {
			if (B[i][j] == 0) {
				for (int k = j; k < c_max; k++) {
					if (B[i][k]) {
						B[i][j] = B[i][k];
						B[i][k] = 0;
						j++;
					}
				}
				break;
			}
		}
	}

	//PRINT_ARR2(10, 10, B[i][j]);

	//행마다 개수 세고 갱신하기(c_max값 갱신하기)
	int c_temp = 0;
	for (int i = 0; i < r_max; i++) {
		int cnter[101];
		fill(cnter, cnter + 101, 0);
		for (int j = 0; j < c_max; j++) {
			if (B[i][j] == 0) break;
			cnter[B[i][j]]++;
		}


		vector <N> v;
		for (int j = 1; j <= 100; j++) {
			if (cnter[j]) {
				N t;
				t.cnt = cnter[j];
				t.number = j;
				v.push_back(t);
			}
		}

		sort(v.begin(), v.end(), cmp);

		//PRINT_ARR(v.size(), v[i].number << "," << v[i].cnt);



		for (int j = 0; j < v.size(); j++) {
			B[i][j * 2] = v[j].number;
			B[i][j * 2 + 1] = v[j].cnt;
		}
		for (int j = v.size() * 2; j < 100; j++) {
			if (B[i][j] == 0) break;
			B[i][j] = 0;
		}
		if (c_temp < v.size() * 2) c_temp = v.size() * 2;
	}
	c_max = c_temp;
}

void C() {
	//위로 밀기(필요 없을 수도,,)
	for (int i = 0; i <  c_max; i++) {
		for (int j = 0; j < r_max; j++) {
			if (B[j][i] == 0) {
				for (int k = j; k < r_max; k++) {
					if (B[k][i]) {
						B[j][i] = B[k][i];
						B[k][i] = 0;
						j++;
					}
				}
				break;
			}
		}
	}

	//PRINT_ARR2(10, 10, B[i][j]);
	//열마다 개수 세고 갱신하기(r_max값 갱신하기)
	int r_temp = 0;
	for (int i = 0; i < c_max; i++) {
		int cnter[101];
		fill(cnter, cnter + 101, 0);
		for (int j = 0; j < r_max; j++) {
			if (B[j][i] == 0) break;
			cnter[B[j][i]]++;
		}
		vector <N> v;
		for (int j = 1; j <= 100; j++) {
			if (cnter[j]) {
				N t;
				t.cnt = cnter[j];
				t.number = j;
				v.push_back(t);
			}
		}
		sort(v.begin(), v.end(), cmp);

		//PRINT_ARR(v.size(), v[i].number << "," << v[i].cnt);

		for (int j = 0; j < v.size(); j++) {
			B[j * 2][i] = v[j].number;
			B[j * 2 + 1][i] = v[j].cnt;
		}
		for (int j = v.size() * 2; j < 100; j++) {
			if (B[j][i] == 0) break;
			B[j][i] = 0;
		}
		if (r_temp < v.size() * 2) r_temp = v.size() * 2;
	}
	r_max = r_temp;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c >> k;
	r--;
	c--;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> B[i][j];
	int cnt = 0;
	do {
		if (B[r][c] == k) break;
		//PRINT_ARR2(15, 15, B[i][j]);
		if (r_max >= c_max) R();
		else C();
		cnt++;
	} while (cnt <= 100);
	//PRINT_ARR2(15, 15, B[i][j]);

	if (cnt > 100) cout << -1;
	else cout << cnt;
	return 0;
}
