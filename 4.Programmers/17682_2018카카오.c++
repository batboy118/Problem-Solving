// Programmers
// no. 17682
// [1차] 다트 던지기
// https://programmers.co.kr/learn/courses/30/lessons/17682
// by JH (batboy118)

#include <string>
#include <cmath>
#include <iostream>
using namespace std;

int arr[3][3];
int score[3];
int solution(string dartResult) {
	int answer = 0;
	int cnt = 0;
	for(int i = 0; i < dartResult.length(); ){
		if(dartResult[i] >= '0' &&  dartResult[i] <= '9'){
			arr[cnt][0] = dartResult[i] - '0';
			i++;
			if(dartResult[i] == '0'){
				arr[cnt][0] *= 10;
				i++;
			}
		}
		if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T'){
			if(dartResult[i] == 'S')
				arr[cnt][1] = 1;
			else if(dartResult[i] == 'D')
				arr[cnt][1] = 2;
			else
				arr[cnt][1] = 3;
			i++;
		}
		if((dartResult[i] == '*' || dartResult[i] == '#') && i < dartResult.length()){
			arr[cnt][2] = dartResult[i];
			i++;
		}
		cnt++;
	}

	for(int i = 0; i < 3; i++){
		score[i] = arr[i][0];
		score[i] = pow(arr[i][0], arr[i][1]);
		if(arr[i][2] == '*'){
			score[i] *= 2;
			if(i > 0){
				score[i - 1] *= 2;
			}
		} else if(arr[i][2] == '#'){
			score[i] *= -1;
		}
	}

	for(int i = 0; i < 3; i++)
		answer += score[i];

	return answer;
}
