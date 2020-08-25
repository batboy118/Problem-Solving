// Programmers
// no. 42841
// 숫자 야구
// https://programmers.co.kr/learn/courses/30/lessons/42841
// by JH (batboy118)

//제출 코드 (without main)
function solution(baseball) {
    var answer = 0;
    var n = ['1','2','3','4','5','6','7','8','9'];
    var visit = [0,0,0,0,0,0,0,0,0]
    function f (depth, num){
        if(depth == 3){
            if(check_valid(num)) answer++;
            return;
        }
        for(let i = 0; i < 9; i++){
            if(visit[i] == 0){
                visit[i] = 1;
                f(depth + 1, num + n[i]);
                visit[i] = 0;
            }
        }
    }
    f(0, '');

    function check_valid(num){
        for(let i = 0; i < baseball.length;i++){
            let ball = 0;
            let strike = 0;
            for(let j = 0; j < 3; j++){
                if(String(baseball[i][0])[j] == num[j]){
                    strike++;
                }
                else{
                    for(let z = 0; z < 3; z++){
                        if(num[j] == String(baseball[i][0])[z]){
                            ball++;
                            break;
                        }
                    }
                }
            }
            if(ball != baseball[i][2] || strike != baseball[i][1]) return 0;
        }
        return 1;
    }
    return answer;
}
