// Programmers
// no. 42885
// 구명보트
// https://programmers.co.kr/learn/courses/30/lessons/42885
// by JH (batboy118)

//제출 코드 (without main)
function solution(people, limit) {
    var answer = 0;
    var h = {};
    for(let i = 0; i < people.length; i++){
        h[people[i]] = (h[people[i]] | 0) + 1;
    }
    let keys = Object.keys(h).sort((a,b) => a - b).map((a) => Number(a));
    if(h[limit / 2]){
        answer += Math.floor(h[limit / 2] / 2);
        h[limit / 2] -=  Math.floor(h[limit / 2] / 2) * 2;
    }
    let left = 0;
    let last = keys.length - 1;
    while(left <= last){
        let temp = keys[left];
        while(h[temp] > 0){
            if(left == last){
                if(limit / 2 >= temp){
                    answer += Math.floor(h[temp] / 2);
                    h[temp] -= Math.floor(h[temp] / 2) * 2;
                    if(h[temp]) answer++;
                    h[temp] = 0;
                }
                else{
                    answer += h[temp];
                    h[temp] = 0;
                }
            }
            else if((keys[last]) + (temp) > limit){
                answer += h[keys[last]];
                h[keys[last]] = 0;
                last--;
            }
            else{
                if(h[temp] >= h[keys[last]]){
                    answer += h[keys[last]];
                    h[temp] -= h[keys[last]];
                    h[keys[last]] = 0;
                    last--;
                } else{
                    answer += h[temp];
                    h[keys[last]] -= h[temp];
                    h[temp] = 0;
                }
            }
        }
        left++;
    }
    return answer;
}
