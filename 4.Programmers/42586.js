// Programmers
// no. 42586
// 기능개발
// https://programmers.co.kr/learn/courses/30/lessons/42586
// by JH (batboy118)

//제출 코드 (without main)
function solution(progresses, speeds) {
    var answer = [];
    var res = progresses.map( (p,i) => Math.ceil((100 - p) / speeds[i]));
    console.log(res)
    for(let i = 0; i < res.length; i++){
        let cnt = 1;
        let val = res[i];
        while(i < res.length - 1 &&  val >= res[i + 1]){
            cnt++;
            i++;
        }
        answer.push(cnt);
    }
    return answer;
}