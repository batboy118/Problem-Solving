// Programmers
// no. 42579
// 베스트앨범
// https://programmers.co.kr/learn/courses/30/lessons/42579
// by JH (batboy118)

//제출 코드 (without main)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct mx
{
	string str= "";
	int first = -1;
	int fi = -1;
	int second = -1;
	int si = -1;
	int total = 0;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
	unordered_map<string, mx> music;

	for(int i = 0; i < genres.size(); i++)
	{
		music[genres[i]].total += plays[i];
		if(plays[i] > music[genres[i]].second)
		{
			if(plays[i] > music[genres[i]].first)
			{
				music[genres[i]].str = genres[i];
				music[genres[i]].second = music[genres[i]].first;
				music[genres[i]].first = plays[i];
				music[genres[i]].si = music[genres[i]].fi;
				music[genres[i]].fi = i;
			}
			else
			{
				music[genres[i]].second = plays[i];
				music[genres[i]].si = i;
			}

		}
	}
	while(!music.empty())
	{
		mx i;
		for (auto it = music.begin();it != music.end(); it++)
		{
			if(i.total < it->second.total)
				i = it->second;
		}
		answer.push_back(i.fi);
		if(i.si > -1)
			answer.push_back(i.si);
		music.erase(i.str);
	}
    return answer;
}
