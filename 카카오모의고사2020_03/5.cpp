#include <stack>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<unordered_map>

int st[200005];

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
	int min;
	int max_gap = 0;
	int temp = 0;

	while(1)
	{
		min = 2000000001;
		for(int i = 0; i < stones.size(); i++)
		{
			if(!st[i] && stones[i] < min)
			{
				min = stones[i];
				//cout << min << '\n';
			}
		}
		temp = 1;
		for(int i = 0; i < stones.size(); i++)
		{
			if(!st[i])
				stones[i] -= min;
			if(!st[i] && stones[i] < 1)
				st[i] = 1;
			if(i > 0 && st[i - 1] && st[i])
			{
				temp++;
			}
			else
			{
				if(temp > max_gap)
					max_gap = temp;
				temp = 1;
			}
		}
	//	cout << max_gap <<' ' << k <<endl;
		if(max_gap <= k)
		{
			answer += min;
		}
		else
			break;
	}
	return answer;
}

int main()
{
	long long k = 3;
	vector<int> stones =  {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
	cout<< solution(stones, k) << ' ';
}
