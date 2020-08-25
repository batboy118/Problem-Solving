// Programmers
// no. 42584
// 주식가격
// https://programmers.co.kr/learn/courses/30/lessons/42584
// by JH (batboy118)

//제출 코드 (without main)
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int,int>> s;
    for(int i = 0; i < prices.size(); i++){
        pair<int, int> temp;
        temp.first = i;
        temp.second = prices[i];
        while(!s.empty() && s.top().second > temp.second){
            answer[s.top().first] = i- s.top().first;
            s.pop();
        }
        s.push(temp);
    }
    while(!s.empty()){
        answer[s.top().first] = prices.size() - 1 - s.top().first;
        s.pop();
    }
    return answer;
}
