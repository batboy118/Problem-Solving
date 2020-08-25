// Programmers
// no. 42747
// H-Index
// https://programmers.co.kr/learn/courses/30/lessons/42747
// by JH (batboy118)

//제출 코드 (without main)
function solution(citations) {
    let answer = 0;
    const sort = citations.sort((a,b) => b-a);
    sort.forEach( (el, i) => {
        if(i+1 <= el) {
            answer = i+1;
        }
    });
    return answer;
}
