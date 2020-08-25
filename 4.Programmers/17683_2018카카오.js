// Programmers
// no. 17683
// [3차] 방금그곡
// https://programmers.co.kr/learn/courses/30/lessons/17683
// by JH (batboy118)

function solution(m, musicinfos) {
    let answer = '(None)';
    let time = -1;
    const objects = [];
    for(let item of musicinfos){
        let info = item.split(",")
        info[0] = info[0].split(":");
        info[1] = info[1].split(":");
        info[0] = Number(info[0][0]) * 60 + Number(info[0][1])
        info[1] = Number(info[1][0]) * 60 + Number(info[1][1])
        objects.push({start:info[0],end:info[1],name:info[2],melody:info[3]})
    }
    let target = [];
    for(let i = 0; i < m.length; i++){
        target.push(m[i + 1] === "#" ? m[i++] + "#" : m[i] );
    }
    for(let s of objects){
        let melody = [];
        for(let i = 0; i < s.melody.length; i++){
            melody.push(s.melody[i + 1] === "#" ? s.melody[i++] + "#" : s.melody[i] );
        }
        while(melody.length < s.end - s.start){
            melody = melody.concat(melody);
        }
        melody = melody.slice(0, s.end - s.start);
        for(let i = 0; i < melody.length; i++){
            let flag = 0;
            for(let j = 0; j < target.length; j++){
                if(target[j] !== melody[i + j]){
                    flag = 1;
                    break;
                }
            }
            if(flag === 0) {
                if(time < s.end - s.start ){
                    answer = s.name;
                    time = s.end - s.start;
                }
                break;
            }
        }
    }
    return answer;
}
