#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
	int temp;
	int target;
	stack<int> s;

	for(int i =0; i<moves.size(); i++)
	{
		temp = -1;
		int x = moves[i] - 1;
		for(int y = 0; y < board.size(); y++)
		{
			if(board[y][x])
			{
				temp = y;
				break;
			}
		}
		if(temp > -1)
		{
			target = board[temp][x];
			board[temp][x] = 0;
			if(!s.empty() && s.top()==target)
			{
				s.pop();
				answer+= 2;
			}
			else
				s.push(target);
		}
	}
    return answer;
}

int main()
{
	vector<vector<int>> b = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
	vector<int> m = {1,5,3,5,1,2,1,4};
	cout << solution(b, m);
}
