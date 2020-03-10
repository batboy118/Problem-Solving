// Programmers
// no. 42576
// 완주하지 못한 선수
// https://programmers.co.kr/learn/courses/30/lessons/42576
// by JH (batboy118)

//제출 코드 (without main)
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
	unordered_map<string, int> diff;

	for(int i = 0; i < participant.size(); i++)
	{
		diff[participant[i]]++;
	}
	for(int i = 0; i < completion.size(); i++)
	{
		diff[completion[i]]--;
	}
	for(int i = 0; i < participant.size(); i++)
	{
		if(diff[participant[i]])
			return participant[i];
	}
    return answer;
}

//main
#include <iostream>

int		main(void)
{
	ios::sync_with_stdio(false);
	//cin.tie(0);
	string ret;
	int	x;
	string temp;
	vector<string> participant;
	vector<string> completion;

	cout<< "마라톤 참가자 수를 수를 입력하세요.";
	cin >> x;
	for(int i = 0; i < x; i++)
	{
		cout<< i + 1 << "번 참가자 이름 : ";
		cin >> temp;
		participant.push_back(temp);
	}
	cout<< "완주자의 수를 입력하세요.";
	cin >> x;
	for(int i = 0; i < x; i++)
	{
		cout<< i + 1 << "번 완주자의 이름 : ";
		cin >> temp;
		completion.push_back(temp);
	}
	ret = solution(participant, completion);
	cout << ret;
	return (0);
}
