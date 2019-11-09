#include <iostream>

using namespace std;


bool solution(int lands[][4] , int wells [][4] , int point[] ){
	bool ans = false;
	int num_lands = sizeof(lands) / 4;
	int num_wells = sizeof(wells) / 4;

	for (int i = 0; i<num_lands; i++) {       //땅이랑 겹치면 false 리턴
		if ((point[0] >= lands[i][2] || point[2] <= lands[i][0] || point[1] >= lands[i][3] || point[3] <= lands[i][1]) == false) return false;
	}

	for (int i = 0; i<num_wells; i++) {   //식수원이 겹치면 true!
		if((point[0] >= wells[i][2] || point[2] <= wells[i][0] || point[1] >= wells[i][3] || point[3] <= wells[i][1]) == false) return true;
	}

	return ans;
}



int main() {

	int lands1 [][4]  = { { 10,0,30,5 },{ 0,30,20,50 },{ 30,30,40,40 } };
	int wells1 [][4]  = { { 10,10,30,30 },{ 40,10,50,20 } };
	int points1 []  = { 15,15,25,25 };
	cout << "1번문제결과:" << solution(lands1, wells1, points1)<< endl;
	
	
	int lands2[][4]  = { { 0, 0, 20, 10 },{ 10, 20, 20, 40 },{ 30, 0, 50, 20 } };
	int wells2 [][4]  = { { 20, 40, 30, 50 },{ 30, 20, 50, 30 } };
	int points2 []  = { 20, 30, 30, 40 };
	cout << "2번문제결과:" << solution(lands2, wells2, points2) << endl;

	return 0;
}