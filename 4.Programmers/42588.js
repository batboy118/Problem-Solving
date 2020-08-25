// Programmers
// no. 42588
// 탑
// https://programmers.co.kr/learn/courses/30/lessons/42588
// by JH (batboy118)

//제출 코드 (without main)
function solution(heights) {
    var answer = [];
    let maxh = heights[0];
    answer.push(0);
    for(let i = 1; i < heights.length; i++){
        if(maxh <= heights[i]){
            maxh = heights[i];
            answer.push(0);
        }
        else{
            let j = i - 1;
            while(j > -1 && heights[j] < heights[i]){
                j--;
            }
            answer.push(j + 1);
        }
    }
    return answer;
}