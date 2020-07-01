// Programmers
// no. 42748
// K번째수
// https://programmers.co.kr/learn/courses/30/lessons/42748
// by JH (batboy118)

//제출 코드 (without main)
function solution(array, commands) {
    return commands.map( cmd => array.slice(cmd[0] - 1, cmd[1]).sort( (a,b) => a - b)[cmd[2] - 1])
}
