// Programmers
// no. 17678
// [1차] 셔틀버스
// https://programmers.co.kr/learn/courses/30/lessons/17678
// by JH (batboy118)

function solution(n, t, m, timetable) {
    let answer = 0;
    var temp = [];
    var time = [];

    for(let i = 0; i < timetable.length; i++){
        temp = (timetable[i].split(':')).map(item => parseInt(item,10));
        time.push((temp[0]*60) + (temp[1]));
    }
    time.sort(function (a,b){
		return a-b;
	});
	console.log(time);
    var list = [];
    for(let i = 0; i < n; i++){
        list.push(9*60 + i*t);
    }

    for(let i=0; i < n - 1; i++){
        for(let j = 0; j < time.length; j++){
            if(j >= m || time[0] > list[i]){
                break;
            } else {
                time.shift();
            }
        }
    }

    answer = list[n - 1];
    for(let i = 1; i < m + 1; i++){
        if(time.length == 0 || time[0] > answer){
            break;
        } else {
            if(i == m){
                console.log(time[0])
                answer = time[0] - 1;
            } else {
                time.shift();
            }
        }
    }

    let res = ''
    res += String(Math.floor(answer/60)).padStart(2, '0') + ':' + String(answer%60).padStart(2, '0');
    return res;
}

console.log(solution(2,10,2,['09:10', '09:09', '08:00', '09:07', '09:55', '17:50', '09:55']));
