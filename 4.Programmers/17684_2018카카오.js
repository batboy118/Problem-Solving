// Programmers
// no. 17684
// [3차] 압축
// https://programmers.co.kr/learn/courses/30/lessons/17684
// by JH (batboy118)

function solution(msg) {
  let answer = [];
  let map = {};
  let index = 1;
  for (let i = 'A'.charCodeAt(0); i <= 'Z'.charCodeAt(0); i++) {
    const c = String.fromCharCode(i);
    if (map[c] === undefined) {
      map[c] = index++;
    }
  }
  for (let i = 0; i < msg.length; i++) {
    let str = msg[i];
    let val;
    while (map[str] && i < msg.length) {
      val = map[str];
      str += msg[++i];
    }
    answer.push(val);
    map[str] = index++;
    i--;
  }
  return answer;
}
