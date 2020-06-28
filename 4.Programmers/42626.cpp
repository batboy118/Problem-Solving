// Programmers
// no. 42626
// 더 맵게
// https://programmers.co.kr/learn/courses/30/lessons/42626
// by JH (batboy118)

//제출 코드 (without main)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    while(pq.top() < K){
        if(pq.size() == 1) return -1;
        int temp = pq.top();
        pq.pop();
        temp += pq.top() * 2;
        pq.pop();
        pq.push(temp);
        ans++;
    }
    return ans;
}