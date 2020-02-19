#include <iostream>
#include <cmath>
#include <vector>
//#define DEB
#define MAX_N 50
#define MAX_C 13
using namespace std;
struct info {
	int x, y;
	int Min;
};
int map[MAX_N][MAX_N];
info H[2 * MAX_N];
info C[MAX_C];
int N, M;
int result;
int houseCount;
int tempTotal;
int chickenCount;
vector<int> Mchicken;

void cal() {
	int temp;
	for (int i = 0; i < houseCount; i++) {
		H[i].Min = 987654321;
	}
	for (int c = 0; c < M; c++) {
		for (int i = 0; i < houseCount; i++) {
			temp = abs(C[Mchicken[c]].x - H[i].x) + abs(C[Mchicken[c]].y - H[i].y);
			if (H[i].Min > temp) H[i].Min = temp;
		}
	}
	tempTotal = 0;
	for (int i = 0; i < houseCount; i++) {
		tempTotal += H[i].Min;
	}
}
void dfs(int depth, int k) {
	if (depth == M) {
#ifdef DEB
		for (int i = 0; i < Mchicken.size(); i++) {
			cout << Mchicken[i] << ' ';
		}
		cout << endl;
#endif
		cal();
		if (result > tempTotal) result = tempTotal;
		return;
	}
	for (int i = k; i < chickenCount; i++) {

			Mchicken.push_back(i);
			dfs(depth + 1, i + 1);
			Mchicken.pop_back();

		
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	houseCount = 0;
	chickenCount = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				H[houseCount].x = j;
				H[houseCount].y = i;
				houseCount++;
			}
			else if (map[i][j] == 2) {
				C[chickenCount].x = j;
				C[chickenCount].y = i;
				chickenCount++;
			}
		}
	}
	
	result = 987654321;
	dfs(0, 0);
	cout << result;
	return 0;
}