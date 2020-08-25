// Programmers
// no. 42577
// 전화번호 목록
// https://programmers.co.kr/learn/courses/30/lessons/42577
// by JH (batboy118)

//제출 코드 (without main)
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> hash_map;

bool solution(vector<string> phone_book) {
	bool answer = true;

	for(int i = 0; i < phone_book.size(); i++)
		hash_map[phone_book[i]] = 1;
	for(int i = 0; i < phone_book.size(); i++) {
		for(int j = 0; j < phone_book.size(); j++) {
			if(i == j)
				continue;
			string phone_number = phone_book[j].substr(0,phone_book[i].size());
			if(phone_number == phone_book[i])
				return false;
		}
	}
	return true;
}
