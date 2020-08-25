// Programmers
// no. 42840
// 모의고사
// https://programmers.co.kr/learn/courses/30/lessons/42840
// by JH (batboy118)

//제출 코드 (without main)
function solution(answers) {
    var answer = [];
    let p = [[1, 2, 3, 4, 5], [2, 1, 2, 3, 2, 4, 2, 5], [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]];
    let s = [0, 0, 0];
    answers.forEach( (ans, idx) =>{
        p.forEach( (pp, pi) =>{
            if(pp[idx % pp.length] === ans){
                s[pi]++;
            }
        }, ans, idx);
    })

    let info = {}
    s.forEach((pp, i) => {
        info[i + 1] = pp;
    })
    let sortedKey = Object.keys(info).sort((a,b) => {
        if(info[a] == info[b])
            return a - b
        return info[b] - info[a]
    })
    sortedKey.some((key, i) =>{
        if(i > 0 && info[key] != info[sortedKey[i - 1]])
            return 1;
        answer.push(Number(key));
    })
    return answer;
}
