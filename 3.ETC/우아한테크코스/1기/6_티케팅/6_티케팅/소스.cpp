#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;



int timeToSec(string time) {
	vector<string> result;
	string token;
	stringstream ss(time);
	char delimiter = ':';

	while (getline(ss, token, delimiter)) {
		result.push_back(token);
	}
	int ans = 0;
	ans += stoi(result[0]) * 3600;
	ans += stoi(result[1]) * 60;
	ans += stoi(result[2]);

	return ans;
}

vector<string> solution(int totalTicket, vector<string>& logs) {
	vector <string> str;
	vector <string> ans;
	string token;
	int tcnt = 0;
	
	int cnt = 0;
	char delimiter = ' ';
	
	for (int i = 0; i < logs.size(); i++) {
		stringstream ss(logs[i]);
		while (getline(ss, token, delimiter)) {
			str.push_back(token);
		}
	}


	//첫 리퀘스트 정보 입력
	int usingStartTime = timeToSec(str[2]);
	bool isUsing = true;
	ans.push_back(str[0]);

	for (int i = 3; i < str.size(); i += 3) {
		int nowTime = timeToSec(str[i + 2]);

		if (tcnt > 10001) break;
		
		if (str[ i + 1 ] == "leave") {
			isUsing = false;
			ans.pop_back();
			tcnt--;
		}
		else if (nowTime - usingStartTime >= 60 || !isUsing) {
			ans.push_back(str[i]);
			usingStartTime = nowTime;
			isUsing = true;
			tcnt++;
		}
		if (nowTime == timeToSec("10:00:00")) break;
	}

	if (ans.size() > 10000) { ans.erase(ans.begin() + 10000, ans.end()); }

	sort(ans.begin(),ans.end());

	return ans;
}


int main() {
	int totalTicket = 2000;
	vector<string> ans1;
	vector<string> ans2;
	vector<string> log1 = {
		"woni request 09:12:29",
		"brown request 09:23:11",
		"brown leave 09:23:44",
		"jason request 09:33:51",
		"jun request 09:33:56",
		"cu request 09:34:02"
	};
	ans1 = solution(totalTicket, log1);
	
	for (int i = 0; i < ans1.size(); i++) {
		cout << ans1[i] <<' ';
	}
	cout << endl;

	vector<string> log2 = {
		"woni request 09:12:29",
		"brown request 09:23:11",
		"brown leave 09:23:44",
		"jason request 09:33:51",
		"jun request 09:33:56", //jun은 jason 접속 땜에x
		"park request 09:34:51", //park는 jason 나오는 동시에 들어감
		"joon request 09:59:00", //서버 종료시간 아슬아슬하게 !
		"cu request 09:59:02"
	};  //woni, jaosn, park, joon 구매 성공

	ans2 = solution(totalTicket, log2);

	for (int i = 0; i < ans2.size(); i++) {
		cout << ans2[i] << ' ';
	}


	return 0;
}