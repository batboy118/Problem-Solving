// Programmers
// no. 43165
// 타겟 넘버
// https://programmers.co.kr/learn/courses/30/lessons/43165
// by JH (batboy118)

//제출 코드 (without main)
#include <string>
#include <vector>
#include <stack>

using namespace std;

void dfs(int depth, int s, int *ans, int target, int len, vector<int>* numbers){
    if(depth == len){
        if(s == target){
            (*ans)++;
        }
        return;
    }
    dfs(depth + 1, s - (*numbers)[depth], ans, target, len, numbers);
    dfs(depth + 1, s + (*numbers)[depth], ans, target, len, numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    stack <int> s;
    dfs(0, 0, &answer, target, numbers.size(), &numbers);
    return answer;
}
