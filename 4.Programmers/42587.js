// Programmers
// no.42587
// 프린터
// https://programmers.co.kr/learn/courses/30/lessons/42587
// by JH (batboy118)

//제출 코드 (without main)
function solution(priorities, location) {
    var answer = 1;
    var cnt = {};
    priorities.forEach( i => cnt[i] = (cnt[i] | 0) + 1);
    let keys = Object.keys(cnt).sort( (a,b) => b - a);
    var marking = priorities[location];
    priorities[location] = -1;
    for(let i = 0 ; keys[i] >= marking; i++){
        while(cnt[keys[i]]){
            if(priorities[0] == keys[i]){
                answer++;
                cnt[keys[i]]--;
                priorities.shift();
            }
            else if(priorities[0] == -1 && keys[i] == marking){
                return answer;
            }
            else{
                priorities.push(priorities[0]);
                priorities.shift();
            }
        }
    }
}