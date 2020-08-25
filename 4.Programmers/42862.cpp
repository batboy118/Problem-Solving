// Programmers
// no. 42862
// 체육복
// https://programmers.co.kr/learn/courses/30/lessons/42862
// by JH (batboy118)

//제출 코드 (without main)
#include <string>
#include <vector>

using namespace std;

int	info[32];

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int	i = 0;

	while(++i <= n)
		info[i] = 1;
	i = -1;
	while(++i < reserve.size())
		info[reserve[i]]++;
	i = -1;
	while(++i < lost.size())
		info[lost[i]]--;
	i = 0;
	while(++i <= n)
	{
		if(info[i])
			answer++;
		else if(info[i - 1] == 2)
			answer++;
		else if(info[i + 1] == 2)
		{
			info[i + 1]--;
			answer++;
		}
	}
	return answer;
}

//main
#include <iostream>

int		main(void)
{
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int ret;
	int	n;
	int	x;
	int temp;
	vector<int> lost;
	vector<int> reserve;

	cout<< "학생의 수를 입력하세요.";
	cin >> n;
	cout<< "체육복을 도난 당한 학생의 수를 입력하세요.";
	cin >> x;
	cout<< "체육복을 도난 당한 학생들의 번호를 입력하세요.";
	for(int i = 0; i < x; i++)
	{
		cin >> temp;
		lost.push_back(temp);
	}
	cout<< "여벌의 체육복을 가지고 있는 학생의 수를 입력하세요.";
	cin >> x;
	cout<< "여벌의 체육복을 가지고 있는 학생들의 번호를 입력하세요.";
	for(int i = 0; i < x; i++)
	{
		cin >> temp;
		reserve.push_back(temp);
	}
	ret = solution(n, lost, reserve);
	cout << ret;
	return (0);
}
