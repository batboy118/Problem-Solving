// Programmers
// no. 17676
// [1차] 추석 트래픽
// https://programmers.co.kr/learn/courses/30/lessons/17676
// by JH (batboy118)

function solution(lines) {
    var answer = 0;
    let list = []
    for(let i in lines){
        let temp = lines[i].split(' ');
        let time = temp[1].split(':').map(function(item) {
            return parseFloat(item, 10);
        });
        let endTime = Math.round((time[0] * 3600 + time[1] * 60 + time[2]) * 1000)/1000;
        let startTime = Math.round((endTime - parseFloat(temp[2])  + 0.001) * 1000)/1000;
        list.push([startTime, endTime]);
    }
    console.log(list)
    for(let i = 0; i < list.length; i++){
        let temp = 0;
        for(let j = i; j < list.length; j++){
            if(list[i][1] + 1 > list[j][0]){
                temp++;
            }
        }
        if(answer < temp)
            answer = temp;
    }
    return answer;
}

console.log(solution(["2016-09-15 01:00:04.001 2.0s","2016-09-15 01:00:07.000 2s"]))
