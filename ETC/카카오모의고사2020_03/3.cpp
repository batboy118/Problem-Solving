#include <stack>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int check[64][10];
int answer = 0;

void dfs(int depth, int n, vector<vector<int>> set)
{
	if(depth == n)
	{
		int flag = 1;
		for(int i = 0; i < answer; i++)
		{
			int flag1 = 0;
			int j = 0;
			while(j < 10)
			{
				if(check[i][j] != check[answer][j])
				{
					flag1 = 1;
					break;
				}
				j++;
			}
			if(!flag1)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			int i = 0;
			while(i < 10)
			{
				cout << (check[answer][i]) << ' ';
				i++;
			}
			cout << endl;
			answer++;
			i = 0;
			while(i < 10)
			{
				check[answer][i] = check[answer-1][i];
				i++;
			}
		}
		return;
	}
	for(int i = 0; i < set[depth].size(); i++)
	{
		if(!check[answer][set[depth][i]])
		{
			check[answer][set[depth][i]] = 1;
			dfs(depth+1, n ,set);
			check[answer][set[depth][i]] = 0;
		}
	}
}

int solution(vector<string> user_id, vector<string> ban_id) {

	int idx;
	int flag;
	vector<int> temp;
	vector<vector<int>> set;

	for(int i = 0; i < ban_id.size(); i++)
	{
		for(int j = 0; j < user_id.size(); j++)
		{
			if(user_id[j].size() != ban_id[i].size())
				continue;
			idx = 0;
			flag = 0;
			while(idx < user_id[j].size())
			{
				if(ban_id[i][idx] == '*')
				{
					idx++;
					continue;
				}
				if (user_id[j][idx] != ban_id[i][idx])
				{
					flag = 1;
					break;
				}
				idx++;
			}
			if(!flag)
				temp.push_back(j);
		}
		set.push_back(temp);
		temp.clear();
	};
	dfs(0, set.size(), set);
    return answer;
}

int main()
{
	vector<string> u = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
	vector<string> b = {"fr*d*", "abc1**"};
	cout << solution(u,b);
}
