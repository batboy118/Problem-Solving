// Programmers
// no. 42577
// 전화번호 목록
// https://programmers.co.kr/learn/courses/30/lessons/42577
// by JH (batboy118)

//제출 코드 (without main)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end());
	for(int i = 0; i < phone_book.size() - 1; i++)
	{
		if(phone_book[i] == phone_book[i+1].substr(0,phone_book[i].size()))
			return false;
	}
    return true;
}
