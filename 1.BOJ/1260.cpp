#include <iostream>
#include <stack>
#include <queue>


using namespace std;

int main(){
	int N, M, start;
	cin >> N >> M >>start;
	int g[N][N];
	int visit[N];
	stack<int> s;
	queue<int> q;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			g[i][j] = 0;
		}
	}
	for(int j = 0; j < M; j++){
		int a, b;
		cin >> a >> b;
		g[a - 1][b - 1] = 1;
		g[b - 1][a - 1] = 1;
	}
	for(int i = 0; i < N; i++){
		visit[i] = 0;
	}
	cout << start-- << ' ';
	visit[start] = 1;
	s.push(start);
	while(!s.empty()){
		int temp = s.top();
		int flag = 0;
		for(int i = 0; i < N; i++){
			if(visit[i] == 0 && g[temp][i]){
				cout << i + 1 << ' ';
				visit[i] = 1;
				s.push(i);
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			s.pop();
		}
	}
	cout << endl;
	for(int i = 0; i < N; i++){
		visit[i] = 0;
	}
	cout << start + 1 << ' ';
	q.push(start);
	visit[start] = 1;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		for(int i = 0; i < N; i++){
			if(visit[i] == 0 && g[temp][i]){
				cout << i + 1 << ' ';
				visit[i] = 1;
				q.push(i);
			}
		}
	}
	return 0;
}
