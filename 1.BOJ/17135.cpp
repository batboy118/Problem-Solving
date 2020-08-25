#include<iostream>
#include<cmath>
#include<vector>

#define endl '\n'
#define MAX 15


using namespace std;
struct info {
	int x;
	int y;
	bool isAlive;
};

int ans;
int tempAns;
int N, M, D;
int map [MAX+1][MAX];
int cnt;

vector <info> enemy;
vector <info> copy_e;

void kill(int h1, int h2, int h3) {
	int temp;
	int tempdist;
	int dist;
	int hunterX[3] = { h1,h2,h3 };
	for (int j = 0; j < 3; j++) {
		 dist= 9999;
		 temp = -1;
		 for (int i = 0; i < enemy.size(); i++) {
			 tempdist = abs(hunterX[j] - enemy[i].x) + abs(N - enemy[i].y);
			 if (tempdist <= D) {
				 if (dist > tempdist) {
					 dist = tempdist;
					 temp = i;
				 }
				 else if (dist == tempdist) {
					 if (enemy[temp].x > enemy[i].x) {
						 temp = i;
					 }
				 }
			 }
		 }
		 if(temp>-1) enemy[temp].isAlive = false;
	}
	for (int i = 0; i < enemy.size(); i++) {
		if (enemy[i].isAlive == false) {
		//	map[enemy[i].y][enemy[i].x]=0;
			enemy.erase(enemy.begin() + i);
			i--;
			tempAns++;
		}
	}
}

bool Down() {
	if (cnt == tempAns) {
		return true;
	}
	if (enemy.size()==0) {
		return true;
	}

	for (int i = 0; i < enemy.size(); i++) {
		enemy[i].y++;
		if (enemy[i].y > N - 1) {
			enemy.erase(enemy.begin() + i);
			i--;
		}
	}
	return false;
}



int  solve() {
	ans = 0;

	for (int i = 0; i < M; i++) {
		for (int j = i+1; j < M; j++) {
			for (int k = j+1; k < M; k++) {
				tempAns = 0;
				enemy.clear();
				for (int id = 0; id<copy_e.size() ; id++) {
					enemy.push_back(copy_e[id]);
				}
				do{
					kill(i, j, k);
				} while (!Down());
				if (ans < tempAns) ans = tempAns;
				
			}
		}
		
	}
	return ans;
};

int main(int argc, char** argv){

	cin >> N >> M >> D;
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j]) { 
				cnt++; 
				info tempinfo;
				tempinfo.x = j;
				tempinfo.y = i;
				tempinfo.isAlive = true;
				copy_e.push_back(tempinfo);
			}
		}
	}
	
	
	cout << solve() << endl;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}