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
		for (stringstream sts(logs[i]); (sts >> w);) {  /// ���ڿ� s�� ������� ���ڿ� ��Ʈ�� sts����
														 /// sts�� ���� �ܾ ���ٸ� NULL ��ȯ
			str.push_back(w);							  /// �ܾ� w�� word�� �߰�
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
		"jun request 09:33:56", //jun�� jason ���� ����x
		"park request 09:34:51", //park�� jason ������ ���ÿ� ��
		"joon request 09:59:00", //���� ����ð� �ƽ��ƽ��ϰ� !
		"cu request 09:59:02"
	};  //woni, jaosn, park, joon ���� ����


	return 0;
}