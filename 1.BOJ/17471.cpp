#include<iostream>
#include<vector>
#include<cmath>

#define endl '\n'
#define MAX 10

using namespace std;

struct info
{
	int man;
	int cnt;
	bool check;
};


int ans;
int N;
int temp;
int number[10]={ 1,2,3,4,5,6,7,8,9,10 };
info Section[10];
vector <vector<int>> Next(10, vector<int>());
vector <int> S1;
vector <int> S2;

bool check() {
	//S1 체크
	
	for (int i = 0; i < N; i++) {
		Section[i].check = false;
	}
		
	if (S1.size() > 1) {
		for (int i = 0; i < S1.size(); i++) {
			for (int j = 0; j < Section[S1[i]].cnt; j++) {
				Section[Next[S1[i]][j]].check = true;
			}
		}

		for (int i = 0; i < S1.size(); i++) {
			if (Section[S1[i]].check == false) return false;
		}
	}

	//S2 체크
	
	for (int i = 0; i < N; i++) {
		Section[i].check = false;
	}

	if (S2.size() > 1) {
		
		for (int i = 0; i < S2.size(); i++) {
			for (int j = 0; j < Section[S2[i]].cnt; j++) {
				Section[Next[S2[i]][j]].check = true;
			}
		}

		for (int i = 0; i < S2.size(); i++) {
			if (Section[S2[i]].check == false) return false;
		}


	}

	int SUM1 = 0;
	int SUM2 = 0;

	for (int i = 0; i < S1.size(); i++) {
		SUM1 += Section[S1[i]].man;
	}
	for (int i = 0; i < S2.size(); i++) {
		SUM2 += Section[S2[i]].man;
	}

	temp = abs(SUM1 - SUM2);

	return true;
}


void  solve() {
	for (int i = 0; i < (1 << N); i++) {
		S1.clear();
		S2.clear();
		for (int j = 0; j < N; j++) {
			if (i&(1 << j)) {
				S1.push_back(j);
			}
			else {
				S2.push_back(j);
			}
		}
		if (S1.size() == 0 || S2.size() == 0) continue;
		else {
			temp = 0;
			if (check()) {
				if (temp < ans) {
					ans = temp;
				}
			}
		}

	}

};

int main(int argc, char** argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Section[i].man;
	}
	for (int i = 0; i < N; i++) {
		cin >> Section[i].cnt;
		for (int j = 0; j < Section[i].cnt; j++) {
			cin >> temp;
			Next[i].push_back(temp-1);
		}
	}
	ans = 987654321;

	solve();
	if (ans == 987654321) ans = -1;

	cout << ans << endl;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}