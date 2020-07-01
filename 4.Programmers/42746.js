// Programmers
// no. 42746
// 가장 큰 수
// https://programmers.co.kr/learn/courses/30/lessons/42746
// by JH (batboy118)

//제출 코드 (without main)
function solution(numbers) {
    var answer = '';
    numbers = numbers.sort( (a,b) => {
        return (String(b)+String(a)) - (String(a)+String(b))
    })
    numbers.forEach((i) => {
        if(answer !== '' || i !== 0)
            answer += i;
    })
    if(answer === '') return '0'
    return answer;
}
