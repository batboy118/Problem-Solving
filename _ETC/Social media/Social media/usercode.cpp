#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define fCNT1 user[uID1].fCnt
#define pCNT1 user[uID1].pCnt
#define fCNT user[uID].fCnt
#define pCNT user[uID].pCnt

struct postInfo {
	int like = 0;
	int timeStamp = 0;
};
struct userInfo {
	int following[1000];
	int post[100000];
	int fCnt = 0;
	int pCnt = 0;
};

postInfo post[100001];
userInfo user[1001];
int postCnt;
int temp[10];
int tempCnt;

std::ofstream out("test.txt");
std::string s;

void sorting1(int pID) {
	int breakPoint;
	for (int i = 0; i < 10; i++) {
		if (post[temp[i]].like < post[pID].like) {
			breakPoint = i;
			break;
		}
		else if (post[temp[i]].like == post[pID].like)
			if (post[temp[i]].timeStamp < post[pID].timeStamp) {
				breakPoint = i;
				break;
			}
	}
	for (int i = 9; i > breakPoint; i--) {
		temp[i] = temp[i - 1];
	}
	temp[breakPoint] = pID;
	return;
}

/*void sorting2(int pID, int timestamp) {
	int breakPoint;
	for (int i = 0; i < 10; i++) {
		if (timestamp - post[temp[i]].timeStamp > 1000) {
			breakPoint = i;
			break;
		}
		else if (post[temp[i]].like < post[pID].like) {
			breakPoint = i;
			break;
		}
		else if (post[temp[i]].like == post[pID].like)
			if (post[temp[i]].timeStamp < post[pID].timeStamp) {
				breakPoint = i;
				break;
			}
	}

	for (int i = 9; i > breakPoint; i--) {
		temp[i] = temp[i - 1];
	}
	temp[breakPoint] = pID;
	return;
}*/

void sorting2(int pID, int timestamp) {
	int breakPoint;
	for (int i = 0; i < 10; i++) {
		if (timestamp - post[temp[i]].timeStamp <= 1000) continue;
		else if (post[temp[i]].timeStamp < post[pID].timeStamp) {
			breakPoint = i;
			break;
		}
	}
	
	for (int i = 9; i > breakPoint; i--) {
		temp[i] = temp[i - 1];
	}
	temp[breakPoint] = pID;
	return;
}
/*
void addList(int uID, int timestamp) {
	for (int i = 0; i < pCNT; i++) {
		if (timestamp - post[temp[9]].timeStamp <= 1000) {
			if (timestamp - post[user[uID].post[i]].timeStamp > 1000) continue;
			else if (post[temp[9]].like > post[user[uID].post[i]].like) continue;
			else if (post[temp[9]].timeStamp >= post[user[uID].post[i]].timeStamp) continue;
			else sorting1(user[uID].post[i]);
		}
		else if (timestamp - post[user[uID].post[i]].timeStamp <= 1000) {
			sorting2(user[uID].post[i], timestamp);
		}
		else{
			if (post[temp[9]].timeStamp >= post[user[uID].post[i]].timeStamp) continue;
			else sorting3(user[uID].post[i], timestamp);
		}
	}
}
*/
void addList(int uID, int timestamp) {
	for (int i = 0; i < pCNT; i++) {

		if (timestamp - post[user[uID].post[i]].timeStamp <= 1000) {
			if (timestamp - post[temp[9]].timeStamp <= 1000) {
				if (post[temp[9]].like < post[user[uID].post[i]].like) {
					continue;
				}
				else if (post[temp[9]].like == post[user[uID].post[i]].like) {
					if (post[temp[9]].timeStamp > post[user[uID].post[i]].timeStamp) continue;
					else sorting1(user[uID].post[i]);
				}
			}
			else {
				
				sorting1(user[uID].post[i]); //
			}
		}
		else {
			if (timestamp - post[temp[9]].timeStamp <= 1000) continue;
			else if (post[temp[9]].timeStamp > post[user[uID].post[i]].timeStamp) continue;
			sorting2(user[uID].post[i], timestamp);				
		}
	}
}


void init(int N)
{
	post[0].like = -1000000;
	post[0].timeStamp = -1000000;
	for (int i = 1; i <= postCnt; i++) {
		post[i].like = 0;
	}
	for (int i = 1; i <= N; i++) {
		user[i].pCnt = 0;
		user[i].fCnt = 0;
	}

	postCnt = 0;
	return;
}

void follow(int uID1, int uID2, int timestamp)
{
	user[uID1].following[fCNT1] = uID2;
	fCNT1++;
	return;
}

void makePost(int uID, int pID, int timestamp)
{
	user[uID].post[pCNT] = pID;
	post[pID].timeStamp = timestamp;
	pCNT++;
	postCnt++;
	return;
}

void like(int pID, int timestamp)
{
	post[pID].like++;
	return;
}

void getFeed(int uID, int timestamp, int pIDList[])
{
	for (int i = 0; i < 10; i++) {
		temp[i] = 0;
	}
	
	addList(uID, timestamp);

	for (int i = 0; i < fCNT; i++) {
		addList(user[uID].following[i], timestamp);
	}

	for (int i = 0; i < 10; i++) {
		//if (temp[i] == 0) break;
		pIDList[i] = temp[i];
		cout << pIDList[i];
		if (i == 9)break;
		cout<<' ';//
	}
	out << endl;//
	cout << timestamp;//
	cout << "##############################################" <<endl;//
	
	for (int i = 0; i < 10; i++) {
		if (pIDList[i] == 0)break;
		cout << pIDList[i] << "/ like :  " << post[pIDList[i]].like
			<< "/ timestamp :  " << post[pIDList[i]].timeStamp <<  endl;
	}

	cout << endl;
	return;
}