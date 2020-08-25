// Programmers
// no. 42862
// 체육복
// https://programmers.co.kr/learn/courses/30/lessons/42862
// by JH (batboy118)

//제출 코드 (without main)
function solution(n, lost, reserve) {
    let lst = [];
    let ans = n;
    for (let i = 0; i < n; i++){
        lst[i] = 1;
    }
    for (let i = 0; i < lost.length; i++){
        lst[lost[i] - 1]--;
    }
    for (let i = 0; i < reserve.length; i++){
        lst[reserve[i] - 1]++;
    }
    for (let i = 0; i < n; i++){
        if(lst[i] == 0){
            if(lst[i - 1] == 2){
                lst[i - 1]--;
                lst[i]++;
            }
            else if(lst[i + 1] == 2){
                lst[i + 1]--;
                lst[i]++;
            }
            else{
                ans--;
            }
        }
    }
    return ans;
}
