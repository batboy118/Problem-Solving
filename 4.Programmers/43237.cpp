// Programmers
// no. 43237
// 예산
// https://programmers.co.kr/learn/courses/30/lessons/43237
// by JH (batboy118)

//제출 코드 (without main)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int		answer = 0;
	long	total = 0;
	int 	min;
	int 	max;
	int		mid;

	max = 0;
	for(int i = 0 ; i < budgets.size(); i++)
	{
		if(max < budgets[i])
			max = budgets[i];
		total += budgets[i];
	}
	if(total <= M)
		return max;
	min = M/budgets.size();
	while(min <= max)
	{
		mid = (min+max)/2;
		total = 0;
		for(int i = 0 ; i < budgets.size(); i++)
		{
			if(mid < budgets[i])
				total += mid;
			else
				total += budgets[i];
		}
		if(total < M)
		{
			answer = mid;
			min = mid + 1;
		}
		else if(total == M)
		{
			answer = mid;
			break;
		}
		else
		{
			max = mid - 1;
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
	int M;
	int x;
	int temp;
	int ret;
	vector<int> budgets;

	cout<< "지방의 수를 입력하세요. (3이상)";
	cin >> x;
	for(int i = 0; i < x; i++)
	{
		cout<< i + 1 << "번 지방 예산 : ";
		cin >> temp;
		budgets.push_back(temp);
	}
	cout<< "국가의 예산 총액을 입력하세요.";
	cin >> M;
	ret = solution(budgets, M);
	cout << ret;
	return (0);
}
