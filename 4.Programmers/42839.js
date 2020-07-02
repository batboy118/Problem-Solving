// Programmers
// no. 42839
// 소수 찾기
// https://programmers.co.kr/learn/courses/30/lessons/42839
// by JH (batboy118)

//제출 코드 (without main)
function is_prime(a) {
    if(a < 2) return 0;
    if(a < 4) return 1;
    for(let i = 2; i * i <= a; i++){
        if(a % i == 0)
            return 0;
    }
    return 1;
}

function solution(numbers) {
    var nums = numbers.split("");
    var lst = [];
    var visit = [0,0,0,0,0,0,0]
    var f = (depth, num) => {
        if(depth == nums.length){
            if(is_prime(Number(num))){
                lst.push(Number(num))
            }
            return;
        }
        for(let i = 0; i < nums.length; i++){
            if(visit[i] == 0){
                visit[i] = 1;
                f(depth + 1, num + String(nums[i]));
                f(depth + 1, num);
                visit[i] = 0;
            }
        }
    }
    f(0, '');
    var numSet = (new Set(lst))
    return numSet.size;
}
