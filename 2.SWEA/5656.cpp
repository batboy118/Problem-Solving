#include<iostream>
#include<queue>
//#define DEB

using namespace std;
int N, W, H;
int Map[15][12];
int result;
bool isEmpty;
bool check[15][12];
queue <pair<int, int>> q;
queue <int> valueQ;

void Arrange(int copyMap[][12]) {
	for (int j = 0; j < W; j++) {
		for (int i = H-1; i > 0; i--) {
			if (copyMap[i][j] == 0) {
				int k = i;
				while (copyMap[k-1][j] == 0) {
					k--;
				}
				if (k-1 < 0)break;
				copyMap[i][j] = copyMap[k - 1][j];		
				copyMap[k - 1][j] = 0;
			}
		}
	}

}

bool Break(int x, int copyMap[][12]) {
	if (0 == copyMap[H - 1][x]) return true;
	int y=0;
	while (copyMap[y][x] == 0) {
	 y++;
	}
	q.push (make_pair(y, x));
	valueQ.push(copyMap[y][x]);
	while (!q.empty()) {

		for (int i = 0; i < valueQ.front(); i++) {
			if (i == 0) copyMap[q.front().first][q.front().second] = 0;
			else
			{
				if (q.front().second - i >= 0 && copyMap[q.front().first][q.front().second-i] !=0) {
					q.push(make_pair(q.front().first, q.front().second-i));
					valueQ.push(copyMap[q.front().first][q.front().second - i]);
					copyMap[q.front().first][q.front().second-i] = 0;
				}
				if (q.front().second + i < W && copyMap[q.front().first][q.front().second+i] != 0) {
					q.push(make_pair(q.front().first , q.front().second + i));
					valueQ.push(copyMap[q.front().first][q.front().second + i]);
					copyMap[q.front().first][q.front().second+i] = 0;
	
				}
				if (q.front().first - i >= 0 && copyMap[q.front().first - i][q.front().second] != 0) {
					q.push(make_pair(q.front().first - i, q.front().second));
					valueQ.push(copyMap[q.front().first - i][q.front().second]);
					copyMap[q.front().first-i][q.front().second] = 0;
	
				}
				if (q.front().first + i < H && copyMap[q.front().first + i ][q.front().second] != 0) {
					q.push(make_pair(q.front().first + i, q.front().second));
					valueQ.push(copyMap[q.front().first + i][q.front().second]);
					copyMap[q.front().first+i][q.front().second] = 0;
				}
			}
		}
		q.pop();
		valueQ.pop();
	}
	return false;
}

void dfs(int depth, int _Map[][12]) {
	depth++;
	int copyMap[15][12];
	for (int i = 0; i < W; i++) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				copyMap[i][j] = _Map[i][j];
			}
		}
		//블럭 깨기
		bool isNothing = Break(i, copyMap);
		if (isNothing) {
			isEmpty = true;
			for (int k = 0; k < W; k++) {
				if (copyMap[H - 1][k] != 0) {
					isEmpty = false;
					break;
				}
			}
			if (isEmpty) {
				result = 0;
				return;
			}
				continue; // 해당 칸에 깰 블럭이 없을 경우
			}

			//블럭 내리기
			Arrange(copyMap);

			if (depth == N) {
				//갱신
				int tempSum = 0;
				for (int j = 0; j < W; j++) {
					for (int i = H - 1; i >= 0; i--) {
						if (copyMap[i][j] == 0) break;
						tempSum++;
					}
				}

				if (result > tempSum) {

					result = tempSum;
				}
				continue;
			}

			dfs(depth, copyMap);

			if (isEmpty) {
				return;
			}
		}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	
	for (test_case = 1; test_case <= T; ++test_case)	{

		cin >> N >> W >> H;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> Map[i][j];
			}
		}
		
		result = 987654321;
		isEmpty = false;
		dfs(0,Map);


		cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}