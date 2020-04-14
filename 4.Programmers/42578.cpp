// Programmers
// no. 42578
// 위장
// https://programmers.co.kr/learn/courses/30/lessons/42578
// by JH (batboy118)

//제출 코드 (without main)
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int ans = 1;
	unordered_map<string, int> item;

	for(int i = 0; i<clothes.size(); i++)
		item[clothes[i][1]]++;
	/*for(int i = 0; i<clothes.size(); i++)
		if(item[clothes[i][1]])
		{
			ans *= (item[clothes[i][1]] + 1);
			item[clothes[i][1]] = 0;
		}
	*/
	for(auto it = item.begin(); it != item.end(); it++)
		ans *= (it->second+1);
	return ans - 1;
}
