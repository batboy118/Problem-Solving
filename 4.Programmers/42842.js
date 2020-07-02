// Programmers
// no. 42842
// 카펫
// https://programmers.co.kr/learn/courses/30/lessons/42842
// by JH (batboy118)

//제출 코드 (without main)
function solution(brown, yellow) {
    var answer = [];
    let garo = 1;
    let sero = 1;
    let total = brown + yellow;
    while(garo >= sero){
        if(total % garo == 0){4
            if(garo >= total / garo){
                sero = total / garo;
                if(brown == (sero * 2 + garo * 2 - 4))
                    return [garo,sero]
            }
        }
        garo++;
    }
}
