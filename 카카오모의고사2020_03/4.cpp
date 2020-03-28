#include <stack>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<unordered_map>


using namespace std;

vector<long long> solution(long long k, vector<long long> r_num) {
	long long temp;
	long long gap;
	unordered_map <long long, long long> room;

	for(int i = 0; i < r_num.size(); i++)
	{
		if(room.end() == room.find(r_num[i]))
			room.insert(make_pair(r_num[i],1));
		else
		{
			gap = 1;
			while(room.end() != room.find(r_num[i] + gap))
				gap++;
			r_num[i] = r_num[i] + gap;
			room.insert(make_pair(r_num[i],1));
		}
	}
    return r_num;
}

int main()
{
	long long k = 10;
	vector<long long> room_number =  {1,3,4,1,3,1};
	 vector<long long> answer = solution(k, room_number);
	for(int i = 0; i<answer.size(); i++)
		cout << answer[i]<< ' ';
}
