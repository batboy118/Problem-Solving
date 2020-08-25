// Programmers
// no. 42883
// 큰 수 만들기
// https://programmers.co.kr/learn/courses/30/lessons/42883
// by JH (batboy118)

//제출 코드 (without main)
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int cnt = 0;
    for(int i = 0; i < number.size() ; i++){
        if(number[i] < number[i + 1]){
            while(i > -1 && number[i] < number[i + 1]){
                number = number.substr(0, i) + number.substr(i + 1);
                --i;
                if(k == ++cnt) return number;
            }
        }
    }
    return number = number.substr(0 , number.size() + cnt - k);
}
