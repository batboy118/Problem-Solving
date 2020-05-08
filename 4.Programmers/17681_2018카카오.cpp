// Programmers
// no. 17681
// [1차] 비밀지도
// https://programmers.co.kr/learn/courses/30/lessons/17681
// by JH (batboy118)

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for(int i = 0; i < arr1.size(); i++){
        string temp = "";
        for(int j = n - 1; j > -1; j--){
             if((arr1[i] >> j) & 1){
                temp += '#';
             }
             else{
                temp += ' ';
             }
        }
        answer.push_back(temp);
    }

    for(int i = 0; i < arr2.size(); i++){
        for(int j = n - 1; j > -1; j--){
             if((arr2[i] >> j) & 1){
                answer[i][n - j - 1] = '#';
             }
        }
        cout << answer[i] << endl;
    }
    return answer;
}

int main(){
    solution(5, {9, 20, 28, 18, 11}, {30, 1, 21, 17, 28});
}
