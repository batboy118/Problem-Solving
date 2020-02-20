#include<iostream>
#include<queue>
#include<vector>

#define endl '\n'

using namespace std;

int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };

struct info {
	int X;
	int Y;
	int Size;
	int cnt;
};

int N;
queue <pair<int,int>> q;
vector <info> Fish;
vector <int> nearFish;
bool visited[20][20];
int map[20][20];
info Shark;
info tempFish;
int fishN;
int time;
int temptime;
bool canEat;

bool isWall(int x, int y) {
	if (x < 0 || x>N-1 || y<0 || y>N-1) return true;
	else return false;
}

bool isBigfish(int x, int y) {
	if (Shark.Size < Fish[map[y][x]].Size)	return true;
	else return false;
}

bool isSmallfish(int x, int y) {
	if (Shark.Size > Fish[map[y][x]].Size)	return true;
	else return false;
}

void search() {

	q.push(make_pair(Shark.Y, Shark.X));
	visited[Shark.Y][Shark.X] = 1;
	canEat = true;
	temptime = 0;

	while (!q.empty()) {
		int Qsize = q.size();
		
		if (nearFish.size()) {
			return;;
		}
		temptime++;
		while (Qsize--)
		{
			int x = q.front().second;
			int y = q.front().first;

			for (int i = 0; i < 4; i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if (isWall(nx,ny) || visited[ny][nx]) continue;
				if (map[ny][nx] >= 0) {
					if (isBigfish(nx, ny)) continue;
					if (isSmallfish(nx, ny)) nearFish.push_back(map[ny][nx]); // Fish �ε��� �ֱ�
				}
				q.push(make_pair(ny,nx));
				visited[ny][nx] = 1;
				

			}
			q.pop();
		}
	}
	canEat = false;
}

void grow() {
	//��� ����� cnt�� �������� size �ø��� cnt �ʱ�ȭ
	if (Shark.Size == Shark.cnt) {
		Shark.Size++;
		Shark.cnt = 0;
	}

	return;
}

void pickOne() {
	//��� ī��Ʈ ����
	Shark.cnt++;
	//�ð� temptime ��ŭ ���̱�
	time += temptime;
	//���� ���ʿ�, ���� ���ʿ� �������
	int High=20;
	int Left=20;
	int nearst;
	for (int i = 0; i < nearFish.size(); i++) {
		if (High > Fish[nearFish[i]].Y) {
			High = Fish[nearFish[i]].Y;
			Left = Fish[nearFish[i]].X;
			nearst = i;
		}
		else if (High == Fish[nearFish[i]].Y) {
			if (Left > Fish[nearFish[i]].X) {
				Left = Fish[nearFish[i]].X;
				nearst = i;
			}
		}
	}
	//��� ��ġ ����
	Shark.X = Fish[nearFish[nearst]].X;
	Shark.Y = Fish[nearFish[nearst]].Y;
	//�ʿ��� ��� ����
	map[Shark.Y][Shark.X] = -1;
}

void updata() {
	//ť Ŭ����
	while (!q.empty())
	{
		q.pop();
	}
	//nearFish ť Ŭ����
	{
		nearFish.clear();
	}
	//���� �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}

void solve(){
	time = 0;
	while (1) {
		search();
		if (!canEat) break;
		pickOne();
		grow();
		updata();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int temp;
	fishN = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
			cin >> temp;
			if (temp < 9 && temp>0){
				map[i][j] = fishN;
				tempFish.X = j;
				tempFish.Y = i;
				tempFish.Size = temp;
				Fish.push_back(tempFish);
				fishN++;
			}
			else if (temp == 0) {
				map[i][j] = -1;
			}
			else if (temp == 9) {
				map[i][j] = -1;
				Shark.X = j;
				Shark.Y = i;
				Shark.Size = 2;
				Shark.cnt = 0;
			}

		}
	}
	solve();
	cout << time;

}