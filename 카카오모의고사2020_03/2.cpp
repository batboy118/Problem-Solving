#include <stack>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp(const vector<int> a, const vector<int> b)
{
	return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
	vector<vector<int>> set;
	vector<int> temp;
	for(int i = 1; i < s.size() - 1; i++)
	{
		if(s[i] == '{')
		{
			i++;
			temp.push_back(atoi(s.c_str() + i));
			while(s[i] != '}')
			{
				if(s[i] == ',')
				{
					i++;
					temp.push_back(atoi(s.c_str() + i));
				}
				i++;
			}
			set.push_back(temp);
			temp.clear();
		}
	}
	sort(set.begin(), set.end(), comp);
	/*for(int i = 0; i < set.size(); i++)
	{
		for(int j = 0; j < set[i].size(); j++)
			cout << set[i][j] <<' ';
			cout << "\n";
	}*/
	int j;
	answer.push_back(set[0][0]);
	for(int i = 1; i < set.size(); i++)
	{
		sort(set[i].begin(), set[i].end());
		j = 0;
		while(j < set[i-1].size() && set[i][j] == set[i - 1][j])
			j++;
		answer.push_back(set[i][j]);
	}
    return answer;
}

int main()
{
	string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
	vector<int> answer = solution(s);
	for(int i = 0; i < answer.size(); i++)
		cout << answer[i] <<' ';
}
