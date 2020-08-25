// Programmers
// no. 42629
// 라면공장
// https://programmers.co.kr/learn/courses/30/lessons/42629
// by JH (batboy118)

//제출 코드 (without main)
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int day = 0;
    priority_queue<int> pq;
    for(int  i = 0; i < dates.size(); i++){
        if(stock >= k)   break;
        stock -= (dates[i] - day);
        k -= (dates[i] - day);
        day = dates[i];
        while(stock < 0){
            stock += pq.top();
            pq.pop();
            answer++;
        }
        pq.push(supplies[i]);
    }
    while(stock < k){
        stock += pq.top();
        pq.pop();
        answer++;
    }
    return answer;
}