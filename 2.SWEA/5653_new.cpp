#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#define BASE 250

using namespace std;

int ans;
struct info {
	int time;
	int cnt;
	int x, y;
};
int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };
int visit[500][500];
int N, M, K;

bool operator<(info a, info b) {
	return a.time < b.time;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(visit, 0, sizeof(visit));
		priority_queue <info> q;
		queue <info> qq;
		cin >> N >> M >> K;
		for (int i = BASE; i < BASE + N; i++) {
			for (int j = BASE; j < BASE + M; j++) {
				cin >> visit[i][j];
				if (visit[i][j]) {
					info temp;
					temp.time = visit[i][j];
					temp.y = i;
					temp.x = j;
					temp.cnt = visit[i][j] * 2;
					q.push(temp);
				}
			}
		}
		while (K--) {
			int len = q.size();
			while (len--) {
				info temp = q.top();
				q.pop();
				temp.cnt--;
				if (temp.time - 1 == temp.cnt) {
					for (int i = 0; i < 4; i++) {
						info next;
						next.y = temp.y + dy[i];
						next.x = temp.x + dx[i];
						if (visit[next.y][next.x] == 0) {
							visit[next.y][next.x] = temp.time;
							next.time = temp.time;
							next.cnt = temp.time * 2;
							qq.push(next);
						}
					}
				}
				if (temp.cnt > 0){
					qq.push(temp);
				}
			}
			while (!qq.empty()) {
				q.push(qq.front());
				qq.pop();
			}
		}
		cout << '#' << test_case << ' ' << q.size() <<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
