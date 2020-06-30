// Programmers
// no. 42628
// 이중우선순위큐
// https://programmers.co.kr/learn/courses/30/lessons/42628
// by JH (batboy118)

//제출 코드 (without main)
function solution(operations) {
    var q = [];
    operations.forEach( item =>{
        item = item.split(' ')
        if(item[0] === 'I'){
            let i = 0;
            while(q.length > i && q[i] > Number(item[1])){
                  i++;
            }
            q.splice(i, 0, Number(item[1]))
        }
        else if(q.length > 0){
            if (item[1] == '1') {
                q.shift();
            }
            else{
                q.pop();
            }
        }
    })
    if(q.length == 0) return [0,0]
    return [q[0], q[q.length - 1]]
}