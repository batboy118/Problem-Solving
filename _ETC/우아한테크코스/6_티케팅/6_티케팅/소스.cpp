#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;


vector<string> solution(int totalTicket, string logs[]) {
	vector <string> str;
	vector <string> ans;
	string w;
	int cnt = 0;
	for (int i = 0; i < sizeof(logs); i++) {
		for (stringstream sts(logs[i]); (sts >> w);) {  /// 문자열 s로 만들어진 문자열 스트림 sts생성
														 /// sts에 남은 단어가 없다면 NULL 반환
			str.push_back(w);							  /// 단어 w를 word에 추가
		}
	}
	int usingStartTime;
	string usingPerson;
	bool isUsing =false;
	for (int i = 0; i < sizeof(logs); i+=3) {
		int nowTime;
		usingStartTime = ;


	}

	sort(ans.begin(),ans.end());
	return ans;
}


int main() {
	int totalTicket = 2000;
	vector<string> ans;
	string log1[] = {
		"woni request 09:12:29",
		"brown request 09:23:11",
		"brown leave 09:23:44",
		"jason request 09:33:51",
		"jun request 09:33:56",
		"cu request 09:34:02"
	};
	ans = solution(totalTicket, log1);
	

	string log2[] = {
		"woni request 09:12:29",
		"brown request 09:23:11",
		"brown leave 09:23:44",
		"jason request 09:33:51",
		"jun request 09:33:56", //jun은 jason 접속 땜에x
		"park request 09:34:51", //park는 jason 나오는 동시에 들어감
		"joon request 09:59:00", //서버 종료시간 아슬아슬하게 !
		"cu request 09:59:02"
	};  //woni, jaosn, park, joon 구매 성공


	return 0;
}