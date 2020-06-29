// Programmers
// no. 42583
// 다리를 지나는 트럭
// https://programmers.co.kr/learn/courses/30/lessons/42583
// by JH (batboy118)

//제출 코드 (without main)

function solution(bridge_length, weight, truck_weights) {
    var answer = 0;
    let passing = [];
    let total = 0;
    let cnt = 0;
    let idx = 0;
    while(cnt != truck_weights.length){
        answer++;
        if(passing.length && answer - passing[0].insert_at == bridge_length)
        {
            cnt++;
            total -= passing[0].w;
            passing.shift();
        }
        if(idx < truck_weights.length && total + truck_weights[idx] <= weight){
            let temp = {};
            temp.w = truck_weights[idx];
            temp.insert_at = answer;
            passing.push(temp);
            total += truck_weights[idx];
            idx++;
        }
       
    }
    return answer;
}