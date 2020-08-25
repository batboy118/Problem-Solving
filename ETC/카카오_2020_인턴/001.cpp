#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
	int left[2] = {3, 0};
	int right[2] = {3, 2};
	//1,4,7
	//3,6,9
	for( int i = 0; i < numbers.size(); i++){
		//cout <<  "L" <<left[0] << left[1] << " , ";
		//cout <<  "R"<< right[0] << right[1] <<endl;
		if(numbers[i] % 3 == 1){
			left[0] = numbers[i] / 3;
			left[1] = 0;
			answer +='L';
		}
		else if(numbers[i] % 3 == 0 && numbers[i] != 0){
			right[0] = numbers[i] / 3 - 1;
			right[1] = 2;
			answer +='R';
		}
		else{
			int r;
			int c = 1;
			if(numbers[i] == 0){
				r = 3;
			} else{
				r = numbers[i] / 3;
			}
			int temp_l = abs(left[0] -  r)  + abs(left[1] - c) ;
			int temp_r = abs(right[0] -  r) + abs(right[1] - c) ;
			if(temp_l > temp_r){
				right[0] = r;
				right[1] = c;
				answer +='R';
			}
			else if(temp_l < temp_r){
				left[0] = r;
				left[1] = c;
				answer +='L';
			} else{
				if(hand == "left"){
					left[0] = r;
					left[1] = c;
					answer +='L';
				}
				else{
					right[0] = r;
					right[1] = c;
					answer +='R';
				}
			}
		}
	}
    return answer;
}
