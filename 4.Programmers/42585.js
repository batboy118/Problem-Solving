// Programmers
// no.42585
// 쇠막대기
// https://programmers.co.kr/learn/courses/30/lessons/42585
// by JH (batboy118)

//제출 코드 (without main)
function solution(arrangement) {
    var answer = 0;
    var st = [];
    var cnt = 0;
    for(let i = 0 ; i < arrangement.length; i++){
        if(arrangement[i] == '('){
            if(arrangement[i+1] == ')'){
                i++;
                answer += cnt;
            }
            else{
                answer++;
                st.push('(');
                cnt++;
            }
        }
        else{
            st.pop();
            cnt--;
        }
    }
    return answer;
}