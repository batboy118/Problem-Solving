#include<iostream>

using namespace std;

struct Core_ {
	int x;
	int y;
	bool did;
};

int N;
int result;
int numC;
int Map[12][12];
int maxC;
int minL;
int cnt;
int numLine;
bool visit[12][12];
Core_ Core[12];

int searchUp(int cur) {
	int temp=0;
	for (int i = Core[cur].y-1; i >= 0; i--) {
		if (visit[Core[cur].x][i] == 0) {
			visit[Core[cur].x][i] = true;
			temp++;
			if (i == 0) { cnt++; }
		}
		else {
			for (int j = i; j < Core[cur].y; j++) {
				visit[Core[cur].x][j] = false;
				temp--;
			}
			break;
		}
	}
	return temp;
}


int searchDown(int cur) {
	int temp = 0;
	for (int i = Core[cur].y + 1; i < N; i++) {
		if (visit[Core[cur].x][i] == 0) {
			visit[Core[cur].x][i] = true;
			temp++;
			if (i == N-1) { cnt++; }
		}
		else {
			for (int j = i; j > Core[cur].y; j--) {
				visit[Core[cur].x][j] = false;
				temp--;
			}
			break;
		}
	}
	return temp;
}


int searchLeft(int cur) {
	int temp = 0;
	for (int i = Core[cur].x - 1; i>= 0; i--) {
		if (visit[i][Core[cur].y] == 0) {
			visit[i][Core[cur].y] = true;
			temp++;
			if (i == 0) { cnt++; }
		}
		else {
			for (int j = i; j < Core[cur].x; j++) {
				visit[i][Core[cur].y] = false;
				temp--;
			}
			break;
		}
	}
	return temp;
}


int searchRight(int cur) {
	int temp = 0;
	for (int i = Core[cur].x + 1; i < N; i++) {
		if (visit[i][Core[cur].y] == 0) {
			visit[i][Core[cur].y] = true;
			temp++;
			if (i == N-1) { cnt++; }
		}
		else {
			for (int j = i; j > Core[cur].x; j--) {
				visit[i][Core[cur].y] = false;
				temp--;
			}
			break;
		}
	}
	return temp;
}




void find(int cur){

	if (maxC > numC - cur + cnt) { return; }
	
	int temp;

	temp=searchUp(cur);
	numLine += temp;
	if(cur+1<=numC)
		find(cur +1);

	if (cur == numC) {
		if (cnt > maxC) {
			maxC = cnt;
			if (numLine < minL) {
				minL = numLine;
			}
		}
		else if (cnt == maxC) {
			if (numLine < minL) {
				minL = numLine;
			}
		}
	}
	cnt--;
	numLine -= temp;
	


	temp=searchDown(cur);
	numLine += temp;
	if (cur + 1 <= numC)
		find(cur + 1);

	if (cur == numC) {
		if (cnt > maxC) {
			maxC = cnt;
			if (numLine < minL) {
				minL = numLine;
			}
		}
		else if (cnt == maxC) {
			if (numLine < minL) {
				minL = numLine;
			}
		}
	}
	cnt--;
	numLine -= temp;


	temp = searchLeft(cur);
	numLine += temp;
	if (cur + 1 <= numC)
		find(cur + 1);

	if (cur == numC) {
		if (cnt > maxC) {
			maxC = cnt;
			if (numLine < minL) {
				minL = numLine;
			}
		}
		else if (cnt == maxC) {
			if (numLine < minL) {
				minL = numLine;
			}
		}
	}
	cnt--;
	numLine -= temp;

	temp = searchRight(cur);
	numLine += temp;
	if (cur + 1 <= numC)
		find(cur + 1);

	if (cur == numC) {
		if (cnt > maxC) {
			maxC = cnt;
			if (numLine < minL) {
				minL = numLine;
			}
		}
		else if (cnt == maxC) {
			if (numLine < minL) {
				minL = numLine;
			}
		}
	}
	cnt--;
	numLine -= temp;

}



int main() {
	int T;
	
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Map[i][j];
				if (Map[i][j]) {
					visit[i][j] = true;
					if (i != 0 && i != N - 1 && j != 0 && j != N - 1) {
						Core[numC].x = i;
						Core[numC].y = j;
						Core[numC].did=false;
						numC++;
					}
				}
				else
				{
					visit[i][j] = false;
				}
			}
		}
		cnt = 0;
		maxC = 0;
		minL = 99999;
		numLine = 0;
		find(0);


		cout << '#' << tc << ' ' << minL << '\n';
	}
}