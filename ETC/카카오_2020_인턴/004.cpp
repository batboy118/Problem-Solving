#include <string>
#include <vector>
#include <iostream>

#define ST 100
#define CN 500
#define E 0
#define W 1
#define S 2
#define N 3
#define INF 1234567890

int visit[26][26];
int dir[26][26];
int dx[4] = {1, -1 , 0, 0};
int dy[4] = {0, 0 , 1, -1};

using namespace std;

int Min = INF;
int temp = 0;
int n;

void dfs(int i, int j, vector<vector<int>> board){
	if(i == n-1 && j == n - 1)
	{
		if(Min > temp)
			Min = temp;
		return;
	}
	for(int d = 0; d<4; d++){
		int y = i + dy[d];
		int x = j + dx[d];
		if(x < 0 || x > n - 1 || y < 0 || y > n - 1 || visit[y][x] || board[y][x])
			continue;
		else
		{
			if(dir[i][j] == d)
				temp += ST;
			else{
				if(dir[i][j] == 0 && d == 1)
					continue;
				else if(dir[i][j] == 1 && d == 0)
					continue;
				else if(dir[i][j] == 2 && d == 3)
					continue;
				else if(dir[i][j] == 3 && d == 2)
					continue;
				temp += ST + CN;
			}

			dir[y][x] = d;
			visit[y][x] = 1;

			dfs(y, x, board);

			visit[y][x] = 0;
			dir[y][x] = -1;

			if(dir[i][j] == d)
				temp -= ST;
			else
				temp -= ST + CN;
		}
	}
}

int solution(vector<vector<int>> board) {
    int answer = 0;
	n = board.size();

	for(int i  = 0; i < n; i++){
		for( int j = 0 ; j < n ; j++){
			dir[i][j] = -1;
		}
	}

	visit[0][0] = 1;

	dir[0][1] = E;
	visit[0][1] = 1;
	visit[1][0] = 0;

	temp = 100;
	dfs (0,1, board);
	dir[0][1] = -1;


	temp = 100;
	dir[1][0] = S;
	dfs (1,0, board);

    return Min;
}


//------------------------------------------------------------------------------

// #include <string>
// #include <vector>
// #include <iostream>

// #define ST 100
// #define CN 500
// #define E 0
// #define W 1
// #define S 2
// #define N 3
// #define INF 1234567890

// int map[26][26];
// int dir[26][26];
// int dx[4] = {1, -1 , 0, 0};
// int dy[4] = {0, 0 , 1, -1};

// using namespace std;

// int solution(vector<vector<int>> board) {
// 	int n = board.size();

// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < n; j++){
// 				map[i][j] = INF;
// 		}
// 	}
// 	dir[0][1] = E;
// 	dir[1][0] = S;
// 	map[0][1] = ST;
// 	map[1][0] = ST;
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < n; j++){
// 			if(i == 0 && j ==0)	continue;
// 			for(int d = 0; d<4; d++){
// 				int y = i + dy[d];
// 				int x = j + dx[d];

// 				if(x < 0 || x > n - 1 || y < 0 || y > n - 1 || board[y][x] || (x == 0 && y == 0)) continue;

// 				//직진 가능(방향 같고) 갱신할 수 있을 때
// 				if(dir[i][j] == d && map[y][x] > map[i][j] + ST)   //같을때는 어떻게 해야하지..;;
// 				{
// 					//cout << "i:" << i << "j : " << j << endl;
// 					//cout << "dir :" << dir[i][j] <<"d : "<< d<< "x: "<< x << "y : "<< y <<endl;
// 					dir[y][x] = d;
// 					map[y][x] = map[i][j] + ST;
// 				}
// 				//꺽어야 하고(방향 다르고) 갱신할 수 있을 때
// 				else if(dir[i][j] != d && map[y][x] > map[i][j] + CN + ST)
// 				{
// 					dir[y][x] = d;
// 					map[y][x] = map[i][j] + CN + ST;
// 				}
// 			}
// 		}
// 		for(int s = 0; s < n; s++){
// 			for(int t = 0; t < n; t++){
// 				cout << map[s][t]  << ' ';
// 			}
// 			cout <<endl;
// 		}
// 		cout <<endl;
// 	}
//     return map[n-1][n-1];
// }


// int main(){
// 	solution({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});
// }
